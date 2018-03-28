import torch
import torch.autograd.Variable as Variable
form torch.utils.data import DataLoader
import carDataset
import resModle

EPOCH=5


transet=carDataset.CarSet(trainDataPath=None,train=True,transform=None)
testset=carDataset.CarSet(testDataPath=None,train=False,transform=None)
trainLoader=DataLoader(transet,batch_size=64,shuffle=True)
testLoader=DataLoader(testset,batch_size=64)

def train():
    pass
def test():
    pass
def demo():
    
if __name__ == '__main__':
    carmodel=resModle.resModel()
    print(carmodel)
