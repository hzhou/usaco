# Brian Lu - Python Solution
# 1 hr - **********
# Took a little while as I wanted to deal with backtracking
# on a loop instead of recursive functions. Not sure if I
# did it properly but it works.

import sys
import time

infile = open("fenceplan.in", "r")

N, M = infile.readline().split()
N, M = int(N), int(M)
x,y = [None]*N,[None]*N
for i in range(N):
  x[i], y[i] = infile.readline().split()
  x[i], y[i] = int(x[i]), int(y[i])
graph = []
for i in range(N):
  graph.append([])
for i in range(M):
  a, b = infile.readline().split()
  a, b = int(a), int(b)
  a-=1
  b-=1
  graph[a].append(b)
  graph[b].append(a)
infile.close()

cache = set()

moonets = []
netminx = []
netmaxx = []
netminy = []
netmaxy = []

moonum = 0
fill = []

for i in range(len(graph)):
  if i not in cache:
    print("newnet")
    moonets.append(1)
    netminx.append(x[i])
    netmaxx.append(x[i])
    netminy.append(y[i])
    netmaxy.append(y[i])
    cache.add(i)
    fill.append((i,0))
    while len(fill) > 0:
      print("*"*len(fill))
      hand = fill.pop()
      if hand[1] in range(len(graph[hand[0]])) and graph[hand[0]][hand[1]] not in cache:
        cache.add(graph[hand[0]][hand[1]])
        fill.append((hand[0],hand[1]+1))
        fill.append((graph[hand[0]][hand[1]],0))
        netminx[moonum], netmaxx[moonum], netminy[moonum], netmaxy[moonum] = (
                        min(netminx[moonum],x[graph[hand[0]][hand[1]]]),
                        max(netmaxx[moonum],x[graph[hand[0]][hand[1]]]),
                        min(netminy[moonum],y[graph[hand[0]][hand[1]]]),
                        max(netmaxy[moonum],y[graph[hand[0]][hand[1]]]))
        moonets[moonum]+=1
      elif hand[1] in range(len(graph[hand[0]])):
        fill.append((hand[0],hand[1]+1))
    moonum+=1

minperimeter = sys.maxsize
for i in range(len(moonets)):
  perimeter = 2*(netmaxx[i]-netminx[i])+2*(netmaxy[i]-netminy[i])
  if perimeter < minperimeter:
    minperimeter = perimeter

#print(minperimeter)

outfile = open("fenceplan.out", "w")
outfile.write(str(minperimeter))
outfile.close()
