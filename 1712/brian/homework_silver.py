# Brian Lu - My Cow Ate My Homework
# ****tttttt at 1 hr
# *********t at 1 hr 20 m

def main():
    scores = readScores()
    N = len(scores)
    lowi = findLowest(1,N-1,scores)
    length = N-1
    # bigaver = mean(scores[1:N])
    total = sum(scores[1:N])
    # aver = ((bigaver*length)-scores[lowi])/(length - 1)
    high = float(total-scores[lowi])/(length-1)
    index = 0
    for eaten in range(2,N-2,1):
        # length = N-eaten
        if eaten >= lowi:
            lowi = findLowest(eaten, N-1, scores)
        # bigaver = ((bigaver*length)-scores[eaten-1])/(length - 1)
        # aver = ((bigaver*length)-scores[lowi])/(length - 1)
        length -= 1
        total -= scores[eaten-1]
        aver = float(total-scores[lowi])/(length-1)

        #print(lowi)
        #aver = ((aver*length)-scores[eaten])/(length-1)
        if aver > high:
            high = aver
            index = eaten
    writeAnswer(str(index))

def findLowest(i1, i2, a):
    lowest = 10001
    index = -1
    for i in range(i1,i2+1,1):
        if a[i] < lowest:
            index = i
            lowest = a[i]
    return index

def mean(numbers):
    return float(sum(numbers)) / max(len(numbers), 1)

def readScores():
    file = open("homework.in","r")
    file.readline()
    return tuple(map(int, file.readline().split()))
    
def writeAnswer(string):
    print(string)
    file = open("homework.out","w")
    file.write(string+"\n")
    file.close()
    

main()
