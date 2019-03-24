//Harry Zhou
//15 min
//Forgot to consider that subtracting the sum of rooms makes room 0 negative - fixed easily by changing N-1 to N
#include <cstdio>
#include <algorithm>
#include <limits.h>

int main() {
    FILE *fileIn = fopen("cbarn.in", "r");
    FILE *fileOut = fopen("cbarn.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    int *rooms = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", rooms+i);
    }

    int sumRooms = 0;
    for (int i=0; i<N; i++) {
        sumRooms += rooms[i];
    }

    int dist = 0;
    for (int i=0; i<N; i++) {
        dist += i*rooms[i];
    }

    int minDist = dist;

    for (int i=0; i<N-1; i++) {
        dist -= sumRooms;
        dist += rooms[i] * (N);
        if (dist < minDist) {
            minDist = dist;
        }
    }

    printf("%d\n", minDist);
    fprintf(fileOut, "%d\n", minDist);
}
