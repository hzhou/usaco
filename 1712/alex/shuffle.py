#20 Minutes

f = open('shuffle.in','r')
ds = f.read().split('\n')
n = int(ds[0]) # how many
ds.pop(0)
a = ds[0].split(' ') # shuffle order
b = ds[1].split(' ')
for x in range(0,n):
  a[x] = int(a[x])-1
def shuffle(old, ara):
  new = []
  for x in range(0,n):
    new.append(old[ara[x]])
  return new
b = shuffle(b,a)
b = shuffle(b,a)
b = shuffle(b,a)
awf = open('shuffle.out','w')
writethis = ''
for x in range(0,n):
  writethis = writethis + b[x] + '\n'
awf.write(writethis)