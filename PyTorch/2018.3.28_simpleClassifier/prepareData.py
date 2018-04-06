import os
import random
dataPath='DATA'
savePath='DATA'

ratio=0.2
trainset=[]
testset=[]

# print(os.listdir('./DATA'))
for fd in os.listdir(dataPath):
    full_path=os.path.join(dataPath,fd)
    for i in os.listdir(full_path):
        tmp=os.path.join(full_path,i)
        tmp=tmp+' '+fd
        trainset.append(tmp)

random.shuffle(trainset)
testnum=round(len(trainset)*ratio)

testset=trainset[0:testnum]
trainset=trainset[testnum:]

with open(os.path.join(savePath,'train.txt'),'w') as f:
    for i in trainset:
        f.write(i)
        f.write('\n')

with open(os.path.join(savePath,'test.txt'),'w') as f:
    for i in testset:
        f.write(i)
        f.write('\n')
