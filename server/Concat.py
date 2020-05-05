import os
from parameter import par
# pars.PATH+file
pars = par()
class Concat():
    def __init__(self,save_file):
        self.names = []
        self.save_file = save_file

    def run(self,pathfile):
        if(pathfile[-3:]==".wc"):
            self.add(pathfile)
        elif(pathfile[-4:]=='.wce'):
            self.add(pathfile)
            self.concat()
            self.clear()

    def add(self,pathfile):
        self.names.append(pathfile)

    def concat(self):
        finame = self.names[-1][0:-4]
        print(finame)
        with open(finame, 'wb') as f:
            for filename in self.names:
                with open(filename, 'rb') as fr:
                    while (True):
                        data = fr.read(pars.LINELEN*pars.LINELEN)
                        if not data: break
                        f.write(data)

    def clear(self):
        for filename in self.names:
            if (os.path.exists(filename)):
                os.remove(filename)
        self.names.clear()


if __name__=="__main__":
    con = Concat()
    path="./SERVER/cn_windows_server_2019_x64_dvd_4de40f33.iso{}.wc"
    for i in range(1,7):
        con.add(path.format(i))
        print(i)
    con.add("./SERVER/cn_windows_server_2019_x64_dvd_4de40f33.iso.wce")
    # con.concat()
    con.clear()