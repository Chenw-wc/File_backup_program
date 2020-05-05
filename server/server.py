from passsock import passiveTCP
from MyThread import MyThread
from parameter import par
from Concat import Concat
import os
import sys


pars = par()


QLEN=pars.QLEN
Lengh_of_communication=pars.Lengh_of_communication
SENDLENGHT=pars.SENDLENGHT

MYUPLOAD = pars.MYUPLOAD
MYDOWNLOAD = pars.MYDOWNLOAD
MYDAYTIME = pars.MYDAYTIME


def file_tables():
    filetables ={}
    if os.path.exists('file_table.txt'):

        with open('file_table.txt', 'r') as f:
            a =str(f.read())
            a = a.split('\n')
            for string in a:
                z = string.split(' ')
                if (len(z) == 2):
                    filetables[z[0]]=z[1]
    return filetables
filetables = file_tables()
#主函数

def main(ip='0.0.0.0', port=80):
    msock = passiveTCP(port, QLEN,ip)

    while(True):
        conn, addr = msock.accept()
        com = conn.recv(Lengh_of_communication)
        com = str(com.decode('utf-8')).strip(b'\x00'.decode())
        print(com,end=' ')
        if(com in pars.Map.keys()):
            t = MyThread(conn, pars.Map[com], filetables,con)
            t.start()
            t.join()
        # print(filetables)

# mmn\asd\2_2.exe

if __name__=='__main__':
    # main('0.0.0.0',80)
    con = Concat('')
    # main('0.0.0.0',4500)
    main('0.0.0.0', 80)
    # if(len(sys.argv)==4):
    #     con = Concat(sys.argv[1])
    #     main(sys.argv[2],int(sys.argv[3]))
    # else:
    #     print("输入错误")

