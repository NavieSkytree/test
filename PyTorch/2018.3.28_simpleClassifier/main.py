import torch
import torch.autograd.Variable as Variable
import torch.optim as optim
form torch.utils.data import DataLoader
import carDataset
import resModle

EPOCH=5
PRINT_INTER=500

def train(trainLoader,net,optimizer,criterion,p_inter):
    for epoch in range(EPOCH):
        running_loss=0.0
        for i,data in enumerate(trainLoader,0):
            inputs,labels=data
            inputs,labels=Variable(inputs),Variable(labels)

            optimizer.zero_grad()
            outputs=net(inputs)
            loss=criterion(outputs,labels)
            loss.backward()
            optimizer.step()
            running_loss+=loss
            if i%p_inter==p_inter-1:
                print('Epoch:',str(epoch),' ','Iter:',str(i),' ','Loss:',running_loss/2000)
    print('Finished')
def test(testLoader,net):

def demo():

if __name__ == '__main__':
    carmodel=resModle.resModel()
    print(carmodel)
    criterion=nn.CrossEntropyLoss()
    optimizer=optim.SGD(carmodel.parameters(),lr=0.001,momentum=0.9)
    transet=carDataset.CarSet(trainDataPath=None,train=True,transform=None)
    testset=carDataset.CarSet(testDataPath=None,train=False,transform=None)
    trainLoader=DataLoader(transet,batch_size=64,shuffle=True)
    testLoader=DataLoader(testset,batch_size=64)

    train(trainLoader=trainLoader,net=carmodel,optimizer=optimizer,criterion=criterion)
