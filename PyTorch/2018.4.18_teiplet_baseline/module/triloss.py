import torch.nn as nn
from torch.autograd import Variable
class tripletLoss():
    def __init__(self,margin):
        self.margin=margin
        self.MarginRankingLoss=nn.MarginRankingLoss(margin=margin)
    def __call__(self,dist_ap,dist_an):
        y=Variable(dist_ap.data.new().resize_as_(dist_ap.data).fill_(1))
        loss=self.MarginRankingLoss(dist_an,dist_ap,y)
        return loss
