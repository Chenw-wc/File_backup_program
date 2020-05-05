#各共享参数
class par():
    def __init__(self):
        self.QLEN = 5
        self.Lengh_of_communication = 45
        self.SENDLENGHT = 1024
        self.LINELEN = 1024
        self.FILEDIR=200

        self.MYUPLOAD = "230"
        self.MYDOWNLOAD = "330"
        self.MYDAYTIME = "530"
        self.PATH='./SERVER/'
        self.SAVE =self.PATH

        self.Map={"530": 'TCPdaytimed',"230": 'TCPrecflies',"330": 'TCPsendfiles'}

