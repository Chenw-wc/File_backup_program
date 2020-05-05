import socket
#底层连接，侦听
def passivesock(servcie, transport, qlen, ip='0.0.0.0'):
    try:
        port = socket.getservbyname(servcie, transport)
    except TypeError:
        port = servcie

    if(transport=='tcp'):
        type = socket.SOCK_STREAM
    else:
        type = socket.SOCK_DGRAM

    server = socket.socket(socket.AF_INET, type)
    server.bind((ip, port))
    if(type==socket.SOCK_STREAM):
        server.listen(qlen)



    return server

def passiveUDP(service, ip='0.0.0.0'):
    return passivesock(service, 'udp',0, ip)

def passiveTCP(service, qlen, ip='0.0.0.0'):
    return passivesock(service, 'tcp', qlen, ip)





if __name__=='__main__':

    print(passiveTCP('daytime',2))