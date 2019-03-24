//Harry Zhou
//15 min
//didn't realize at first that the entries weren't sorted
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("cowqueue.in", "r");
    FILE *fileOut = fopen("cowqueue.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    int *arrivals = new int[N];
    int *durations = new int[N];

    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", arrivals+i, durations+i);
    }
    
    int *plist = new int[N];
    for (int i=0; i<N; i++) {
        plist[i]=i;
    }
    std::sort(plist, plist+N, [arrivals](int a, int b){return arrivals[a]<arrivals[b];});
    /*for (int i=0; i<N; i++) {
        printf("%d\n", plist[i]);
    }
    printf("\n");*/
    
    int finishTime = 0;
    for (int j=0; j<N; j++) { //changed this at last moment, so the use of variables is a bit strange
        int i = plist[j];
        if (arrivals[i] > finishTime) {
            finishTime = arrivals[i] + durations[i];
        }
        else {
            finishTime += durations[i];
        }
        //printf("%d\n", finishTime);
    }
    //printf("\n");

    printf("%d\n", finishTime);
    fprintf(fileOut, "%d\n", finishTime);
}
