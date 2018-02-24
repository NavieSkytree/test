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
x=torch.randn(5,4)
print(x)
print(x[:,2:4])
print(x.view(20))
print(x.view(-1,5).size())# -1会自动确定

import numpy as np
n1=np.ones([5,3])
n2=torch.from_numpy(n1)
n3=n2.numpy()
print(n1,n2,n3)
print('_____________________')
n2.add_(1)
print(n1,n2,n3)
# numpy和torch共享内存

# 使用cuda
t=[torch.randn(5,5).cuda() if torch.cuda.is_available() else torch.randn(5,5)]
print(t)
