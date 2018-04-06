import torch
from torch.autograd import Variable
import torch.optim as optim
from torch.utils.data import DataLoader
import torchvision.transforms as transforms
import torch.nn as nn
import carDataset
import resModle
import os
import PIL
EPOCH=20
PRINT_INTER=1
BATCH_SIZE=128
trainsetPath='./DATA/train.txt'
testsetPath='./DATA/test.txt'
demoPath='./DEMOIMG'

imgtransforms=transforms.Compose([transforms.Resize((256,256)),
                                  transforms.ToTensor(),
                                  transforms.Normalize([0.485,0.456,0.406],[0.229,0.224,0.225])])

def train(trainLoader,net,optimizer,criterion,p_inter):
    for epoch in range(EPOCH):
        running_loss=0.0
        for i,data in enumerate(trainLoader,0):
            inputs,labels=data
            # print(inputs,labels)
            inputs,labels=Variable(inputs.cuda()),Variable(labels.squeeze(1).cuda())
            optimizer.zero_grad()
            outputs=net(inputs)
            # print(outputs,labels)
            loss=criterion(outputs,labels)
            loss.backward()
            optimizer.step()
            running_loss+=loss
            if i%p_inter==0:
                print('Epoch:',str(epoch),' ','Iter:',str(i),' ','Loss:',running_loss.cpu().data.numpy()[0]/p_inter)
        print('EPOCH FINISHED')
    torch.save(net.state_dict(),'TrainedModel.pkl')
    print('Finished')
def test(testLoader):
    net=resModle.resModel().cuda()
    print(net)
    net.load_state_dict(torch.load('TrainedModel.pkl'))
    crooc=0
    total=0
    for i,data in enumerate(testLoader,0):
        img,label=data
        img,label=Variable(img.cuda()),Variable(label.squeeze(1).cuda())
        # print(img,label)
        outputs=net(img)
        _,predicted=torch.max(outputs,1)
        total+=label.size(0)
        crooc+=(predicted==label).sum()
    print(crooc,total)
    print('Accuracy:',(crooc.cpu().data.numpy()/total)[0])
def demo(path,imgtrans):
    net=resModle.resModel().cuda()
    net.load_state_dict(torch.load('TrainedModel.pkl'))
    imgList=os.listdir(path)
    for i in imgList:
        img=PIL.Image.open(os.path.join(demoPath,i))
        if imgtrans is not None:
            img=imgtrans(img)
        output=net(Variable(img.cuda()).unsqueeze(0))
        # print(output.data)
        _,predicted=torch.max(output,1)
        print(i,predicted.cpu().data.numpy()[0])


if __name__ == '__main__':
    carmodel=resModle.resModel().cuda()
    # print(carmodel)
    criterion=nn.CrossEntropyLoss()
    optimizer=optim.SGD(carmodel.parameters(),lr=0.001,momentum=0.9)
    transet=carDataset.CarSet(DataPath=trainsetPath,eva=False,transform=imgtransforms)
    testset=carDataset.CarSet(DataPath=testsetPath,eva=False,transform=imgtransforms)
    trainLoader=DataLoader(transet,batch_size=BATCH_SIZE,num_workers=32,shuffle=True)
    testLoader=DataLoader(testset,batch_size=4,num_workers=32,shuffle=False)

    # train(trainLoader=trainLoader,net=carmodel,optimizer=optimizer,criterion=criterion,p_inter=PRINT_INTER)
    # test(testLoader=testLoader)
    demo(demoPath,imgtransforms)
