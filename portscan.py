import sys
import os
import socket
import nmap

nm = nmap.PortScanner()
nm.scan('www.baidu.com','1-1024')

for host in nm.all_hosts():
    print ('xxxxxxxxxxxxxxxxxxxxxxx')
    print ('Host : {0}({1})'.format(host,nm[host].hostname()))
    print ('State : {0}'.format(nm[host].state()))

    for proto in nm[host].all_protocols():
        print ('Protocol :　{0}'.format(proto))
        lport = list(nm[host][proto].keys())
        lport.sort()

        for port in lport:
            print('port : {0}\tstate : {1}'.format(port,nm[host][proto][port]))
            print('xxxxxxxxxxxxxxxxxxx')













































