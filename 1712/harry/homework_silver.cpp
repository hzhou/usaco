//Harry Zhou
//1 hour
//Made debug change and forgot to change it back
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("homework.in", "r");
    
    int N;
    fscanf(fileIn, "%d", &N);

    int *qL = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", qL+i);
    }

    /*printf("qL:");
    for (int i=0; i<N; i++) {
        printf("%2d", qL[i]);
    }
    printf("\n");*/

    int *minL = new int[N];
    int min = 10000;
    for (int i=N-1; i>=0; i--) {
        if (qL[i] < min) {min = qL[i];}
        minL[i] = min;
    }
    
    /*printf("minL:");
    for (int i=0; i<N; i++) {
        printf("%2d", minL[i]);
    }
    printf("\n");*/

    int total = 0;
    for (int i=0; i<N; i++) {
        total += qL[i];
    }
    //printf("total: %d\n", total);
    
    float *aL = new float[N-2];
    float max = 0;
    int numMax = 0;
    for (int i=1; i<N-1; i++) {
        total -= qL[i-1];
        int remain = N-i-1;
        float avg = (float)(total-minL[i])/(float)remain;
        if (avg > max + 0.00001) {
            max=avg;
            numMax = 0;
        }
        if (std::abs(max-avg) < 0.00001){
            numMax++;
        }
        aL[i-1] = avg;
    }
    
    /*printf("aL:");
    for (int i=0; i<N; i++) {
        printf(" %f", aL[i]);
    }
    printf("\n");
    printf("numMax: %d\nmax: %f\n", numMax, max);*/

    int *finalL = new int[numMax];
    int index = 0;
    for (int i=0; i<N-2; i++) {
        if (std::abs(aL[i] - max) < 0.00001) {
            finalL[index] = i+1;
            index++;
        }
    }

    std::sort(finalL, finalL+numMax);

    /*for (int i=0; i<numMax-1; i++) {
        printf("%d ", finalL[i]);
    }
    printf("%d\n", finalL[numMax-1]);*/
    
    FILE *fileOut = fopen("homework.out", "w");

    for (int i=0; i<numMax; i++) {
        fprintf(fileOut, "%d\n", finalL[i]);
    }
}
