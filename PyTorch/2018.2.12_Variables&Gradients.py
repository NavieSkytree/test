'''
# Variables and Gradients
'''
from torch.autograd import Variable
import torch

# x=Variable(torch.ones(4,3),requires_grad=True)
# print(x)
# y=x+2
# print(y)
# print(y.grad_fn)
# z=y*y*3
# out=z.mean()
# print(z,out)
# out.backward()
# print(x.grad)

x=Variable(torch.randn(3),requires_grad=True)
y=x*2
while y.data.norm() < 1000:
    y=y*2
print(y)
