import torch.nn as nn
import torch.nn.functional as F
from torchvision import models
class resModel(nn.Module):
    def __init__(self):
        super(resModel,self).__init__()
        model=models.resnet18(pretrained=True)
        self.models=nn.Sequential(model.conv1,model.bn1,model.relu,
                                  model.maxpool,model.layer1,model.layer2,
                                  model.layer3,model.layer4,model.avgpool)
        self.fc_last=nn.Linear(512,2)

    def forward(self,input):
        predict=self.fc_last(self.models(input))
        return predict

if __name__ == '__main__':
    model=resModel()
    print(model)
