//Harry Zhou


#include <cstdio>
#include <algorithm>
int nearest(int N, int *pos, int i) { //right = 1, left = -1;
    if (i == 0) {
        return 1;
    }
    if (i == N-1) {
        return -1;
    }
    if ( pos[i+1]-pos[i] < pos[i]-pos[i-1] ) {
        return 1;
    }
    return -1;
}

int main() {
    FILE *fileIn = fopen("hoofball.in", "r");

    int N;
    fscanf(fileIn, "%d", &N);

    int *pos = new int[N];
    for (int i=0; i<N; i++){
        fscanf(fileIn, "%d", pos+i);
    }

    std::sort(pos, pos+N);

    for (int i = 0; i<N; i++) {
        printf("%4d", pos[i]);
    }
    printf("\n");

    printf("%d %d\n", nearest(N, pos, 0), nearest(N,pos,N-1));

    int *sinkPoints = new int[N];
    for (int i=0; i<N-1; i++) {
        if (nearest(N, pos, i) == 1 && nearest(N, pos, i+1) == -1) {
            sinkPoints[i] = 1;
            sinkPoints[i+1] = 1;
        }
    }
    
    int *passedTo = new int[N];
    for (int i=0; i<N; i++) {
        if (sinkPoints[i] == 1) {
            continue;
        }
        passedTo[ i+nearest(N, pos, i) ] = 1;
    }

    int unusedSinks = 0;
    for (int i=0; i<N; i++) {
        if (sinkPoints[i] == 0) {
            continue;
        }
        if ( passedTo[i] == 1 || passedTo[i+nearest(N, pos, i)] == 1 ) {
            continue;
        }
        unusedSinks++;
    }
    
    int sources = 0;
    for (int i = 0; i<N; i++) {
        if (sinkPoints[i] == 1) {
            continue;
        }
        if (passedTo[i] == 0) {
            sources++;
        }
    }

    printf("%d\n", sources + unusedSinks );

    FILE *fileOut = fopen("hoofball.out", "w");
    fprintf(fileOut, "%d\n", sources + unusedSinks/2);
}
