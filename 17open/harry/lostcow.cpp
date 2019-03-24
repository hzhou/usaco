//Harry Zhou
//20 minutes
//Initially misinterpreted problem. I thought farmer John would always move all the wait to his target point, even after finding Bessie. Turns out he just stops at Bessie's position.
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("lostcow.in", "r");
    FILE *fileOut = fopen("lostcow.out", "w");
    
    int x;
    int y;
    fscanf(fileIn, "%d %d", &x, &y);

    if (x == y) {
        fprintf(fileOut, "%d\n", 0);
        exit(0);
    }
    int currPos = 1;
    int totalDist = 1;
    int comparator = (x<y);
    while ((currPos+x<y) == comparator && currPos+x!=y) {
        totalDist += std::abs(currPos*3);
        currPos = -currPos*2;
    }
    totalDist -= abs(currPos+x-y);
    printf("%d\n", totalDist);
    fprintf(fileOut, "%d\n", totalDist);
}
