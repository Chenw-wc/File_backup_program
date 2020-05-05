import time
def TCPdaytimed(fd):
    a = str(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
    fd.send(a.encode())
    fd.close()