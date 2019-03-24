#2 Hours

f = open('billboard.in','r')
ds = f.read().split("\n")
xv = []
yv = []
for x in range(0,3):
  ds[x] = ds[x].split(' ')
for x in range(0,3):
  for y in range(0,2):
    c = 2*y
    xv.append(int(ds[x][c]))
    yv.append(int(ds[x][c+1]))
area = (xv[1]-xv[0])*(yv[1]-yv[0])+(xv[3]-xv[2])*(yv[3]-yv[2])
check = 0
if xv[0] > xv[5] or yv[0] > yv[5]:
  check = 1
if check == 0:
  area = area - max(0,(min([xv[1],xv[5]])-max([xv[0],xv[4]])))*max(0,(min([yv[1],yv[5]])-max([yv[0],yv[4]])))
check = 0
if xv[2] > xv[5] or yv[2] > yv[5]:
  check = 1
if check == 0:
  area = area - max(0,(min([xv[3],xv[5]])-max([xv[2],xv[4]])))*max(0,(min([yv[3],yv[5]])-max([yv[2],yv[4]])))
pz = open('billboard.out','w')
write = str(area)+ '\n'
pz.write(write)
