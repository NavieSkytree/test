import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.autograd import Variable
from torchvision import models,transforms
from PIL import Image
class resModel(nn.Module):
    def __init__(self):
        super(resModel,self).__init__()
        model=models.resnet18(pretrained=True)
        self.models=nn.Sequential(model.conv1,model.bn1,model.relu,
                                  model.maxpool,model.layer1,model.layer2,
                                  model.layer3,model.layer4,model.avgpool)
        self.fc_last=nn.Linear(512*2*2,2)

    def forward(self,input):
        out=self.models(input)
        out=out.view(-1,512*2*2)
        predict=self.fc_last(out)
        # predict=self.models(input)
        # print(predict.size())
        return predict

if __name__ == '__main__':
    model=resModel()
    print(model)
    img=Image.open('./DATA/0/man_0.jpg').convert('RGB')
    imgtransforms=transforms.Compose([transforms.Resize((256,256)),transforms.ToTensor()])
    img=imgtransforms(img)
    img=torch.unsqueeze(img,0)
    print(model(Variable(img)).data)

    
    # model=models.resnet18()
    # print(model)
