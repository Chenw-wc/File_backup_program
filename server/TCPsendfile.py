from parameter import par
import os.path
pars = par()
#发送文件
def TCPsendfiles(fd):
    filename = fd.recv(pars.FILEDIR)
    filename = filename.decode('utf-8').strip(b'\x00'.decode())
    print('下载文件: ', filename, ' ', end=' ')
    if os.path.isfile(pars.PATH+filename):
        with open(pars.PATH+filename, 'rb') as f:
            while(True):
                data = f.read(pars.SENDLENGHT)
                if not data:break
                fd.send(data)
    else:
        fail = "不存在此文件!"
        fd.send(fail.encode())
        print('失败',end=' ')
    print(fd)
    backmassage = "dowmload "+filename
    with open(pars.PATH+'/record/recode_all.txt','a') as f:
        f.write(backmassage+'\n')
    fd.close()
