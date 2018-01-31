#!/usr/bin/env python3

import matplotlib.pyplot as plt 
file = open('select.txt','r')
file2 = open('insert.txt','r')
file3= open('quick.txt','r')
x=[]
y=[]
x2=[]
y2=[]
x3=[]
y3=[]
for i in file.read().split('\n'):
	
	try:
		x.append(int(i.split()[0]))
		y.append(float(i.split()[1]))
		
	except IndexError:
		pass
for i in file2.read().split('\n'):
	
	try:
		x2.append(int(i.split()[0]))
		y2.append(float(i.split()[1]))
		
	except IndexError:
		pass
for i in file3.read().split('\n'):
	
	try:
		x3.append(int(i.split()[0]))
		y3.append(float(i.split()[1]))
		
	except IndexError:
		pass			


plt.plot(x,y,label='select')
plt.plot(x2,y2,label='insert')
plt.plot(x3,y3,label='quick')
plt.xlabel('n')
plt.ylabel('time')

plt.legend()
plt.show()
