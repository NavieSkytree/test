'''
#1 tensor
'''
import torch
# Tensor的创建
x=torch.Tensor(5,3)
print(x)
y=torch.rand(5,3)
print(y)
print(x.size())
# Tensor的运算
z=torch.rand(4,1)
print(torch.add(z,20))
# Tensor的inplace运算，固定用法添加post_fixed'_'
print(z.add_(1))
# Tensor的维度转换
