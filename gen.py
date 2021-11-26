#!/usr/bin/env python3

import re, os
import json
from datetime import date
import socket
from shutil import copyfile

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind(('localhost', 10043))
serversocket.listen(1) # become a server socket, maximum 5 connections

while True:
    connection, address = serversocket.accept()
    buf = connection.recv(8096).decode('utf-8')
    if len(buf) > 0:
        print(re.search(r'{.+}',buf).group())
        break

serversocket.shutdown(socket.SHUT_RDWR)
serversocket.close()
j = json.loads(re.search(r'{.+}',buf).group())
print(j)
print(j['name'])

if not os.path.exists(j['group']):
    os.makedirs(j['group'])

newdir = os.path.join( os.getcwd(), j['group'])
print(newdir)
os.chdir(newdir)

if not os.path.exists(j['name']):
    os.makedirs(j['name'])

newdir = os.path.join( os.getcwd(), j['name'])
print(newdir)
os.chdir(newdir)

p1 = "/home/dc/compprog/USACO/Template/main.cpp"
p2 = os.path.join(os.getcwd(),"main.cpp")

copyfile(p1,p2)

append = f'// Author : 3\n// Date : {date.today().strftime("%m/%d/%y")}\n// Problem Name : {j["name"]}\n// Content : {j["group"]}\n// Memory Limit : {j["memoryLimit"]}\n// timeLimit : {j["timeLimit"]}\n'

if ( j['input']['type'] == 'stdin'):
    fileName = "test"
else:
    fileName = j["input"]["fileName"].replace(".in","")

with open(p2,"r+") as f:
    content = f.read()
    f.seek(0,0)
    f.write(append + content)

with open(p2,"r") as f:
    content = f.read()

new = content.replace("fileName",fileName)

with open(p2,"w") as f:
    f.write(new)

p1 = "/home/dc/compprog/USACO/Template/compile.sh"
p2 = os.path.join(os.getcwd(),"compile.sh")

copyfile(p1,p2)

with open(p2,"r") as f:
    content = f.read()

new = content.replace("test",fileName)

with open(p2,"w") as f:
    f.write(new)

os.chmod(p2,0o711)

inf = os.path.join(os.getcwd(),f'{fileName}.in')
outf = os.path.join(os.getcwd(),f'{fileName}.out')
expf = os.path.join(os.getcwd(),f'{fileName}.exp')
errf = os.path.join(os.getcwd(),f'{fileName}.err')

with open(inf,'w') as f:
    f.write(j["tests"][0]["input"])

with open(expf,'w') as f:
    f.write(j["tests"][0]["output"])

with open(outf,'w') as f:
    f.write("")

with open(errf,'w') as f:
    f.write("")
