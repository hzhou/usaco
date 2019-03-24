#28 Minutes

f = open('measurement.in','r')
ds = f.read().split('\n')
n = int(ds[0])
ds.pop(0)
m = 7
e = 7
b = 7
for x in range(0,n):
  ds[x] = ds[x].split(' ')
newlist = []
order = []
def maxes(aa,bb,cc):
  maxx = max([aa,bb,cc])
  themaxes = []
  if aa == maxx:
    themaxes.append('a')
  if bb == maxx:
    themaxes.append('b')
  if cc == maxx:
    themaxes.append('c')
  themaxes.sort()
  return(themaxes)
for x in range(0,n):
  order.append(int(ds[x][0]))
for x in range(0,n):
  newlist.append(ds[order.index(min(order))])
  ds.pop(order.index(min(order)))
  order.pop(order.index(min(order)))
days = 0
for x in range(0,n):
  oldmaxes = maxes(m,e,b)
  if newlist[x][1] == 'Bessie':
    b += int(newlist[x][2])
  elif newlist[x][1] == 'Mildred':
    m += int(newlist[x][2])
  elif newlist[x][1] == 'Elsie':
    e += int(newlist[x][2])
  if maxes(m,e,b)!= oldmaxes:
    days+=1
asdf = open('measurement.out','w')
writethis = str(days) + '\n'
asdf.write(writethis)
