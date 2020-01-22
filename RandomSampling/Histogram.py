from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

#Good Rejection

f=open("coordinates_GR.txt", "r")
lines=f.readlines()
x=[]
for i in lines:
    x.append(float((i.split(' ')[0]))/100)
    
y=[]
for i in lines:
    y.append(float((i.split()[1]))/100)

f.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

hist, xedges, yedges = np.histogram2d(x, y, bins=(220,220))
xpos, ypos = np.meshgrid(xedges[:-1]+xedges[1:], yedges[:-1]+yedges[1:])

xpos = xpos.flatten()/2.
ypos = ypos.flatten()/2.
zpos = np.zeros_like (xpos)

dx = xedges [1] - xedges [0]
dy = yedges [1] - yedges [0]
dz = hist.flatten()

ax.bar3d(xpos, ypos, zpos, dx, dy, dz, color='b', zsort='average', alpha=0.9)
plt.title("Markov Good Rejection")
plt.xlabel ("X")
plt.ylabel ("Y")

plt.show()

#Bad Rejection

f=open("coordinates_inside_BR.txt", "r")
lines=f.readlines()
x=[]
for i in lines:
    x.append(float((i.split(' ')[0]))/100)
    
y=[]
for i in lines:
    y.append(float((i.split()[1]))/100)

f.close()


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

hist, xedges, yedges = np.histogram2d(x, y, bins=(200,200))
xpos, ypos = np.meshgrid(xedges[:-1]+xedges[1:], yedges[:-1]+yedges[1:])

xpos = xpos.flatten()/2.
ypos = ypos.flatten()/2.
zpos = np.zeros_like (xpos)

dx = xedges [1] - xedges [0]
dy = yedges [1] - yedges [0]
dz = hist.flatten()

ax.bar3d(xpos, ypos, zpos, dx, dy, dz, color='r', zsort='average', alpha=0.9)
plt.title("Markov Bad Rejection")

plt.xlabel ("X")
plt.ylabel ("Y")

plt.show()