# -*- coding: utf-8 -*-

import numpy as np
from sklearn.metrics import roc_curve
import matplotlib.pyplot as plt

score = np.loadtxt('nsfw_predict_crop.txt', dtype=float, usecols=(0))
label = np.loadtxt('nsfw_predict_crop.txt', dtype=float, usecols=(1))

#print(label)
#print(score)
# score = [-i for i in score]
fpr,tpr,threshold = roc_curve(label, score, pos_label=1)

with open("data.txt",'w') as f:
    for i in range(len(tpr)):
        f.write(str(tpr[i]))
        f.write('\n')


pos = 3729
print('recall:',tpr[pos])
thre=threshold[pos]
print('threshold:',thre)
tmp=0
rightNum = 0
totalNum = 0
for i in range(len(label)):
    if score[i]>=thre:
        if label[i] == 1:
            rightNum = rightNum + 1
        totalNum = totalNum + 1
print("precision:",rightNum/totalNum)
rightNum = 0
totalNum = 0
for i in range(len(label)):
    if score[i]>thre:
        tmp=1
    else:
        tmp=0
    if tmp == label[i]:
        rightNum = rightNum + 1
    totalNum = totalNum + 1
print("accuracy:",rightNum/totalNum)
print("right:",rightNum)
print("total:",totalNum)
plt.plot(fpr,tpr)
plt.show()
