import os

dataPath=''
savePath=''

ratio=0.2
folders=os.listdir(dataPath)
trainset=[]
testset=[]

for fd in folders:
    full_path=os.path.join(dataPath,fd)
    for i in os.listdir(full_path):
        tmp=os.path.join(full_path,i)
        tmp=tmp+fd
        trainset.append(tmp)

trainset.shuffle()
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
