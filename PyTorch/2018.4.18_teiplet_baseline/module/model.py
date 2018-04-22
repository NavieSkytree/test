import torch.nn as nn
from torchvision import models,transforms
class res18(nn.Module):
    def __init__(self):
        super(model,self).__init__()
        model=models.resnet18()
        self.models=nn.Sequential(model.conv1,model.bn1,model.relu,model.maxpool,
                                  model.layer1,model.layer2,model.layer3,model.layer4,model.avgpool)
        self.fc_last=nn.Linear(512*2*2,2)
    def forward(self,inputs):
        out-self.models(inputs)
        out=out.view(-1,512*2*2,2)
        predict=self.fc_last(out)
        return predict

class res50(nn.Module):
    def __init__(self):
        super(res50, self).__init__()
    def forward(self,inputs):
        pass

if __name__ == '__main__':
