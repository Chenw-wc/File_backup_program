import os
a = b'asd.docx\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
# print(a.decode('utf-8').strip(b'\x00'.decode())=='asd.docx')

# try:
#     with open('asd.txt', 'rb') as f:
#         print(f.read(102))
# except:

# os.makedirs('./SERVER/asd')
#
# with open('./SERVER/asd/asd.txt','wb') as f:
#     f.write(a)

# b = 'asd.txt'
# print(b.rfind('/'))
#
# a = -1
# cl = 5
# print(max(-1,5))
# import crc8
# hash = crc8.crc8()
# hash.update('asssbc'.encode('utf-8'))
# print(hash.hexdigest())


# a = 'asdasdtxtzip'
#
# print(a.split("."))
# print(a)
#
# import os
# path = "./SERVER/"+'trans/mmn.zip'  # 文件路径
# if os.path.exists(path):  # 如果文件存在
#     # 删除文件，可使用以下两种方法。
#     os.remove(path)
#     print('asd')

def file_tables(filetables):

    if os.path.exists('file_table.txt'):

        with open('file_table.txt', 'r') as f:
            a =str(f.read())
            a = a.split('\n')
            for string in a:
                z = string.split(' ')
                print(z)
                if(len(z)==2):
                    filetables[z[0]]=z[1]
    return filetables

if __name__=='__main__':
    filetables = {}
    a = file_tables(filetables)
    print(filetables)
