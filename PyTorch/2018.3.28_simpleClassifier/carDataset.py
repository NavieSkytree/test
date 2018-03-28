from torchvision import transforms
from torch.utils.data import Dataset
from PIL import Image

class CarSet(Dataset):
    def __init__(self,trainDataPath=None,train=True,transform=None,testDataPath=None):
        super(CarSet,self).__init__()
        self.train=train
        self.transform=transform
        self.imgpath=[]
        self.labels=[]
        # trainDataPath and testDataPath are all txt file including images path,specifically trainDataPath have labels
        if self.train:
            if trainDataPath is None:
                throw "trainDataPath is invalid"
            with open(trainDataPath,'r') as f:
                ipathAndLabel=f.readline()
                while ipathAndLabel:
                    imgpath.append(ipathAndLabel.split(' ')[0])
                    labels.append(ipathAndLabel.split(' ')[1])
                    ipathAndLabel=f.readline()
        else:
            if testDataPath is None:
                throw "testDataPath is invalid"
            with open(testDataPath,'r') as f:
                ipath=f.readline()
                while ipath:
                    imgpath.append(ipath)
                    ipath=f.readline()

    def __getitem__(index):
        if self.train:
            img=readImg(self.imgpath[index])
            if self.transform is not None:
                img=self.transform(img)
            label=self.label[index]
            return img,label
        else:
            img=readImg(self.imgpath[index])
            if self.transform is not None:
                img=self.transform(img)
            return img

    def __len__(self):
        return len(self.imgpath)

    def readImg(self,path):
        return Image.open(path)
