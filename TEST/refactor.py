import os
data = ''
with open('fv_result_64.txt','r') as f:
    data = f.read()
data = data.split('\n')
rightNum = 0 
with open('crop_predict.txt','w') as f:
    for i in range(len(data)):
        entry = data[i]
        if (entry == ''):
            continue
        entry = entry.split('\t')
        tmp = entry[0].split('/')
        name = tmp[-1]
        if (tmp[-1][0:3] == 'neg'):
            f.write('-'+entry[2])
            f.write('\t')
            f.write('0') 
            f.write('\t')
            f.write(name)
            f.write('\n')
            continue
        # 处理正样本
        tmp = tmp[-1]
        tmp = tmp.split('.')[0]
        tmp = tmp.split('_')[1]
        # if (tmp == entry[1].split('.')[0]):
        if (tmp == entry[1]):
            f.write('-'+entry[2])
            f.write('\t')
            f.write('1')
            f.write('\t')
            f.write(name)
            f.write('\n')
            rightNum = rightNum + 1
            continue
        else:
            f.write('-'+entry[2])
            f.write('\t')
            f.write('0')
            f.write('\t')
            f.write(name)
            f.write('\n')
            continue
print(rightNum)


