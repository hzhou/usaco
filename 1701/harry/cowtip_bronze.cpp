//Harry Zhou
//45 min
//initally scanned with %d, but that didn't work because numbers were not spaced
#include <cstdio>
#include <algorithm>

void flipIfNeeded(int *grid, int N, int x, int y, int &counter) {
    //printf("%d\t(%d, %d): %d\n", y*N+x, x, y, grid[y*N+x]);
    if (!grid[y*N+x]) {
        return;
    }
    counter++;
    for (int i=0; i<=x; i++) {
        for (int j=0; j<=y; j++) {
            grid[j*N+i] = grid[j*N+i] ? 0 : 1; //flips value
        }
    }
}

int main() {
    FILE *fileIn = fopen("cowtip.in", "r");
    FILE *fileOut = fopen("cowtip.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    int *grid = new int[N*N]; //1 if tipped
    for (int j=0; j<N; j++) {
        char *s = new char[N+1];
        fscanf(fileIn, "%s", s);
        for (int i=0; i<N; i++) {
            grid[j*N+i] = s[i] - '0';
        }
    }
    
    /*for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", grid[j*N+i]);
        }
        printf("\n");
    }*/
    
    int level = N-1;
    int phase = 0; //0 = corner, 1 = x, 2 = y;
    int index = 0;
    int counter = 0;

    while (level != 0) {
        if (phase==0) {
            flipIfNeeded(grid, N, level, level, counter);
        }
        if (phase==1) {
            flipIfNeeded(grid, N, index, level, counter);
        }
        if (phase==2) {
            flipIfNeeded(grid, N, level, index, counter);
        }
        index--;
        
        //advance to next phase
        if (index==-1) {
            if (phase==0) {
                phase=1;
                index = level-1;
            }
            else if (phase==1) {
                phase=2;
                index = level-1;
            }
            else if (phase==2) {
                phase=0;
                level--;
                index=0;
            }
        }
    }
    flipIfNeeded(grid, N, 0, 0, counter);

    fprintf(fileOut, "%d\n", counter);

}
