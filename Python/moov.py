import os
binPath = r'I:\Users\SKYTREE\Downloads\ffmpeg-20180802-c9118d4-win64-static\bin\ffmpeg.exe'
srcPath = r'C:\视频样例\原视频'
dstPath = r'C:\视频样例\原视频new'
files = os.listdir(srcPath)
for i in files:
    src = os.path.join(srcPath, i)
    dst = os.path.join(dstPath, i)
    command = '{} -i {} -movflags faststart {}'.format(binPath, src, dst)
    print(command)
    os.system(command)