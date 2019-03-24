//Harry Zhou
//45 minutes
//My first problem was writing 3 instead of N-1, because in the example N was 4 and I was looking at the example while writing that piece of code.
//I originally just had one flag, but then I thought that might be causing a problem, so I sacrificed a bit of readability and efficiency to make two flags.
//That didn't actually solve any problems, but I didn't bother changing it back to one flag because it didn't cause any either.
//Finally, since an input line could be up to 10 digits, I tried using an int64_t.
//Turns out that's not enough. You also need to change your specifier from %d to %ld.
//That's it for the main problems I had to debug.
//Took me a bit of time to figure out the algorithm, but it ended up being pretty simple.
#include <cstdio>
#include <algorithm>

struct rect {
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
    int flag2;
};

int main() {
    FILE *fileIn = fopen("art.in", "r");
    FILE *fileOut = fopen("art.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    int *grid = new int[N*N];
    for (int i=0; i<N; i++) {
        int64_t t;
        fscanf(fileIn, "%ld", &t);
        for (int j=N-1; j>=0; j--) {
            grid[i*N+j] = t%10;
            t /= 10;
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d", grid[i*N+j]);
        }
        printf("\n");
    }

    rect rects[9];
    for (int i = 0; i < 9; i++) {
        rects[i].x1 = N-1;
        rects[i].y1 = N-1;
        rects[i].x2 = 0;
        rects[i].y2 = 0;
        rects[i].flag = 0;
        rects[i].flag2 = 1;
        int col = i+1;

        for (int pos = 0; pos < N*N; pos++) {
            if (grid[pos] == col) {
                int x = pos%N;
                int y = pos/N;
                rects[i].flag = 1;
                if (x<rects[i].x1) {
                    rects[i].x1=x;
                }
                if (x>rects[i].x2) {
                    rects[i].x2=x;
                }
                if (y<rects[i].y1) {
                    rects[i].y1=y;
                }
                if (y>rects[i].y2) {
                    rects[i].y2=y;
                }
            }
        }
    }

    for (int i=0; i<9; i++) {
        if (!rects[i].flag) {
            continue;
        }

        for (int j=i+1; j<9; j++) {
            if (!rects[i].flag) {
                continue;
            }

            int x1 = std::max(rects[i].x1, rects[j].x1);
            int y1 = std::max(rects[i].y1, rects[j].y1);
            int x2 = std::min(rects[i].x2, rects[j].x2);
            int y2 = std::min(rects[i].y2, rects[j].y2);

            for (int x = x1; x <= x2; x++) {
                for (int y = y1; y<= y2; y++) {
                    if (grid[y*N+x] == i+1) {
                        rects[i].flag2 = 0;
                    }
                    else if (grid[y*N+x] == j+1) {
                        rects[j].flag2 = 0;
                    }
                }
            }
        }
    }

    int numfirst = 0;
    for (int i=0; i<9; i++) {
        if (rects[i].flag2 && rects[i].flag) {
            numfirst++;
        }
    }

    printf("%d\n", numfirst);
    fprintf(fileOut, "%d\n", numfirst);
}
