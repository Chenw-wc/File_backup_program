import zipfile
from parameter import par
import os


pars = par()

#解压文件，并将压缩文件删除
def uncompresss(filename):
    zipFile = zipfile.ZipFile(filename)
    for file in zipFile.namelist():
        zipFile.extract(file, pars.PATH)
    zipFile.close()
    if os.path.exists(filename):
        os.remove(filename)

if __name__=="__main__":
    uncompresss(pars.PATH+'trans/mmn.zip')
