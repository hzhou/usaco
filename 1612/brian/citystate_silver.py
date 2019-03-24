#CITYSTATE - Brian Lu - 1st attempt ~30 min
#*xxxxxtttt


file = open("citystate.in","r")
N = int(file.readline().strip())
cities = []
connections = {}
states = []
for i in range(N):
    city,state = file.readline().split()
    if not state in states:
        states.append(state)
        connections[state] = []
    connections[state].append((city,i))
    cities.append((city,i,state))
file.close()

pairs = 0
for city in cities:
    if city[0][0:2] in states:
        for othercity in connections[city[0][0:2]]:
            if othercity[0][0:2] == city[2]:
                pairs+=1
pairs/=2

file = open("citystate.out","w")
file.write(str(int(pairs))+"\n")
file.close()
