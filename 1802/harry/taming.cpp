//Harry Zhou
//22 min
//--
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("taming.in", "r");

    int N;
    fscanf(fileIn, "%d", &N);

    int *counter = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", counter+i);
    }
    
    FILE *fileOut = fopen("taming.out", "w");
    
    counter[0] = 0;
    for (int i=0; i<N; i++) {
        if (counter[i] >= 0) {
            for (int j=1; j<=counter[i]; j++) {
                if ( ( counter[i-j] != -1 && counter[i-j] != counter[i]-j ) || i-j<0 ) {
                    printf("-1\n");
                    fprintf(fileOut, "-1\n");
                    exit(0);

                }
                counter[i-j] = counter[i]-j;
            }
        }
    }
    
    int min = 0;
    int max = 0;
    for (int i=0; i<N; i++) {
        if (counter[i] == 0) {
            min++;
            max++;
        }
        else if (counter[i] == -1) {
            max++;
        }
    }

    printf("%d %d\n", min, max);
    fprintf(fileOut, "%d %d\n", min, max);
}
