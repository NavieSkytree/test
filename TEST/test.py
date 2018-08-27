import os
root = r'I:\Users\SKYTREE\Downloads\image_downloader_gui_v1.0.5\download_images\hand'
files = os.listdir(root)
for i in range(len(files)):
    if files[i] == '':
        continue
    srcfile = os.path.join(root, files[i])
    dstfile = os.path.join(root, 'hand_'+str(i)+'.jpg')
    os.rename(srcfile, dstfile)
    

