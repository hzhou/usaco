#include <stdio.h>
/* Yunru wang
1702
crossroad */

int main() {
    /******** INPUT ******/
    int N;
    FILE *In = fopen("crossroad.in", "r");
    fscanf(In, "%d", &N);

    // printf("N=%d\n", N);

    int Cow[10];
    for (int i=0; i<10; i++){
        Cow[i] = -1;
    }
    int fcount = 0;
    for (int i=0; i<N; i++){
        int cow, side;
        fscanf(In, "%d %d", &cow,&side);
        //printf(" --> cow %d, side %d, prev at %d\n", cow, side, Cow[cow-1]);
        cow--;
        if (Cow[cow] != -1 && Cow[cow] != side) {
            fcount++;
            //printf("cow %d crossed, count = %d\n", cow+1, fcount);
        }
        Cow[cow]=side;
    }
    fclose(In);

    FILE* Out = fopen("crossroad.out", "w");
    fprintf(Out, "%d\n", fcount);
    fclose(Out);
    return 0;
}



