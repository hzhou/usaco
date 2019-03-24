# ~1 hr 10 mins
# *XX*X*X*X*

# The way this program deals with indices is weird when the index is next to a dividing line.
# This means that there will be issues when the target index is near the left end of a "region".
#
# I've yet to fix that.
#
# To be honest "sector" may have been a better word than region.

import math
def main():
    file = open("cowcode.in", "r")
    word, N = file.read().split()
    w = len(word)
    N = int(N)
    file.close()

    index = N-1
    region=findRegion(index,word)
    initialregion=region
    passes=0

    print("INITIAL: region",region,"index",index)

    while region!=0:
        region-=1
        sub = (len(word)*(2**region))
        index-=sub
        region=findRegion(index,word)
        passes+=1
        print("PASS",passes,": region",region,"index",index,"sub",sub)

    ans = word[(index-(passes)+w)%len(word)]

    file = open("cowcode.out", "w")
    file.write(str(ans)+"\n")
    file.close()


def findRegion(i,l):
    region=0
    while i+1 > len(l)*(2**region):
        region+=1
    return region

main()
#C O W|W C O|O C O W W C|C C O W W C O O C O W W
#0 1 2 3 4 5 6>7<8 9 1011121314151617181920212223
#C O W|? ? ?|? ? ? ? ? ?
#    UNI1        UNI2
