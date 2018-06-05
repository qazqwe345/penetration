
import zipfile
import threading

def extractFile(zFile,password):
    try:
        zFile.extractall(pwd=password)

        print("Found Password: " , password)
        return password
    except Exception as e:
        print(e)
        pass

def main():
    zFile = zipfile.ZipFile('userdata.zip')
    passFile = open('passwords.txt','r')
    for line in passFile.readlines():
        password = line.strip('\n').strip('\r').strip('\n').strip('\r').strip('\n').strip('\r')
        extractFile(zFile,password)
        
    else:print ('failed')


if __name__=='__main__':
    main()
