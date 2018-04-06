from torchvision import transforms
from torch.utils.data import Dataset,DataLoader
from PIL import Image
import torch
class CarSet(Dataset):
    def __init__(self,DataPath=None,eva=True,transform=None,evaDataPath=None):
        super(CarSet,self).__init__()
        self.eva=eva
        self.transform=transform
        self.imgpath=[]
        self.labels=[]
        # trainDataPath and testDataPath are all txt file including images pathS and labels
        if not self.eva:
            if DataPath is None:
                raise Exception('DataPath is invalid')
            with open(DataPath,'r') as f:
                ipathAndLabel=f.readline()
                while ipathAndLabel:
                    self.imgpath.append(ipathAndLabel.split(' ')[0])
                    self.labels.append(int(ipathAndLabel.split(' ')[1]))
                    ipathAndLabel=f.readline()
        else:
            if evaDataPath is None:
                raise Exception('evaDataPath is invalid')
            with open(evaDataPath,'r') as f:
                ipath=f.readline()
                while ipath:
                    self.imgpath.append(ipath)
                    ipath=f.readline()

    def __getitem__(self,index):
        if not self.eva:
            img=self.readImg(self.imgpath[index])
            # print(self.imgpath[index])
            if self.transform is not None:
                img=self.transform(img)
            label=self.labels[index]
            # return img,torch.LongTensor([label])
            return img,torch.LongTensor([label])
            # return img
        else:
            img=self.readImg(self.imgpath[index])
            if self.transform is not None:
                img=self.transform(img)
            return img

    def __len__(self):
        return len(self.imgpath)

    def readImg(self,path):
        return Image.open(path)

if __name__ == '__main__':
    trainsetPath='./DATA/train.txt'
    testsetPath='./DATA/test.txt'
    imgtransforms=transforms.Compose([transforms.Resize((256,256)),transforms.ToTensor()])
    trainset=CarSet(DataPath=trainsetPath,eva=False,transform=imgtransforms)
    testLoader=DataLoader(dataset=trainset,batch_size=4,num_workers=4,shuffle=False)
    it=iter(testLoader)
    print(it.next())
