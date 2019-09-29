N=6
grid = [1,1,1,1,1,0,
1,0,0,0,1,1,
1,0,1,1,0,1,
1,0,0,0,1,1,
1,1,0,0,1,0,
0,1,1,1,1,1]
used = set()
blobs = []

def fill(i, blobsIndex):
    global used, grid
    blobs[blobsIndex][0]+=1
    used.add(i)
    x = i%N
    y = i//N
    openSides = 4
    if (x+1) in range(N) and grid[i+1]:
        openSides-=1
        if (i+1) not in used: fill(i+1,blobsIndex)
    if (x-1) in range(N) and grid[i-1]:
        openSides-=1
        if (i-1) not in used: fill(i-1,blobsIndex)
    if (y+1) in range(N) and grid[i+N]:
        openSides-=1
        if (i+N) not in used: fill(i+N,blobsIndex)
    if (y-1) in range(N) and grid[i-N]:
        openSides-=1
        if (i-N) not in used: fill(i-N,blobsIndex)
    blobs[blobsIndex][1]+=openSides

##for i in range(N):
##    for j in range(N):
##        print(grid[i*N+j],end="|")
##    print()
    
blobCount = 0
for i in range(len(grid)):
    if grid[i] and i not in used:
        blobs.append([0,0])
        fill(i, blobCount)
        blobCount+=1

blobs.sort()
blobs.reverse()
print(blobs[0][0], blobs[0][1])

        
