//Harry Zhou
//15 min
//hps.in was empty when testing so that was why my answer didn't match the test case at first
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("hps.in", "r");
    FILE *fileOut = fopen("hps.out", "w");

    char arr1[] = {2, 3, 1}; //n beats arr[n-1]
    char arr2[] = {3, 1, 2};
    
    int N;
    fscanf(fileIn, "%d", &N);

    int *cow1 = new int[N];
    int *cow2 = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", &cow1[i], &cow2[i]);
    }
    
    int win1 = 0;
    int win2 = 0;
    for (int i=0; i<N; i++) {
        if (cow2[i] == arr1[cow1[i]-1]) {win1++;}
        if (cow2[i] == arr2[cow1[i]-1]) {win2++;}
    }

    fprintf(fileOut, "%d\n", std::max(win1, win2));
    printf("%d\t%d\n", win1, win2);
    printf("%d\n", std::max(win1, win2));
}
