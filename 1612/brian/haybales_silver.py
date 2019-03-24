#HAYBALES - Brian Lu - 1st attempt ~25 min
#***ttttttt

file = open("haybales.in", "r")

N,Q=tuple(map(int,file.readline().split()))
haybales=list(map(int,file.readline().split()))
queries=[]
for i in range(Q):
    queries.append(tuple(map(int,file.readline().split())))
file.close()

haybales.sort()

output = []
for query in queries:
    contains = 0
    for haybale in haybales:
        if haybale >= query[0] and haybale <= query[1]:
           contains+=1
        elif query[1] < haybale:
            break
    output.append(contains)

file = open("haybales.out","w")
for line in output:
    file.write(str(line)+"\n")
file.close()