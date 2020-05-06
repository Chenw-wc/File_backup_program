from parameter import par
import os
import crc8
from uncompress import  uncompresss


pars = par()
#初始化文件路径
def Fileinit(file):
    index=file.rfind('/')
    index2 = file.rfind('\\')
    if(index+index2==-2):return
    index = max(index, index2)
    try:
        os.makedirs(pars.SAVE+file[0:index])
    except FileExistsError:
        return



#接收传输来的文件
def TCPrecflies(fd, filetables, con):
    pars.SAVE+=con.save_file
    hash = crc8.crc8()
    file = fd.recv(pars.FILEDIR)
    file = file.decode('utf-8').strip(b'\x00'.decode())
    Fileinit(file)
    crc = fd.recv(pars.Lengh_of_communication)
    crc=str(crc)[2:4]
    if(file in filetables.keys()):
        if(filetables[file]==crc):
            fd.send("END".encode())
            return 0
    filetables[file] = crc
    fd.send("SEND".encode())
    with open(pars.SAVE+file, 'wb') as f:
        while True:
            Data = fd.recv(pars.LINELEN)
            if not Data:break
            f.write(Data)

    socketname = fd.getsockname()
    soceketpeer = fd.getpeername()
    fd.close()

    with open(pars.SAVE+file,'rb') as f:
        CrCData = f.read()
        hash.update(CrCData)
        backmassage = file
        if(hash.hexdigest() in crc):
            backmassage = "right  "+backmassage
            print("right", end=' ')
        else:
            backmassage = "fail  "+backmassage
            print("fail", end=' ')

    with open(pars.PATH+'/record/recode_all.txt','a') as f:
        f.write(backmassage+'\n')
    sign = file.split(".")
    if(sign[-1]=='zip'):
        uncompresss(pars.PATH+file)

    with open('file_table.txt','w') as f:
        for key in filetables.keys():
            f.write(key+' '+filetables[key]+'\n')
    print(hash.hexdigest(), '上传文件: ', file, ' 本地地址:', socketname,'  对端地址:',soceketpeer)
    con.run(pars.PATH + file)
    return 0
