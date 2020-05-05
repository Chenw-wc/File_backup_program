#多线程入口
import threading
from TCPdaytimed import TCPdaytimed
from TCPrecfile import TCPrecflies
from TCPsendfile import TCPsendfiles
from Concat import Concat

class MyThread (threading.Thread):
    def __init__(self, fd, fun, filetables, con):
        threading.Thread.__init__(self)
        self.fd = fd
        self.fun = fun
        self.filetables = filetables
        self.con = con

    def run(self):
        if(self.fun=='TCPdaytimed'):
            TCPdaytimed(self.fd)
        elif(self.fun=='TCPrecflies'):
            TCPrecflies(self.fd, self.filetables, self.con)

        elif(self.fun=='TCPsendfiles'):
            TCPsendfiles(self.fd)