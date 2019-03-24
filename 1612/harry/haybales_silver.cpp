//Harry Zhou
//Forgot to start timer
//Spent a while trying to fix a typo
#include <cstdio>
#include <algorithm>

int bsearch(int *array, int value, int lower, int upper) {
    int mid = (lower + upper) / 2;
    if (upper<lower) { //if not found return index before
        return upper;
    }
    else if (value == array[mid]) {
        return mid;
    }
    else if (value < array[mid]) {
        return bsearch(array, value, lower, mid-1);
    }
    else {
        return bsearch(array, value, mid+1, upper); //made typo here (wrote "value" instead of "upper")
    }
}

int main() {
    FILE *fileIn = fopen("haybales.in", "r");
    FILE *fileOut = fopen("haybales.out", "w");

    int N;
    int Q;
    fscanf(fileIn, "%d %d", &N, &Q);

    int *locations = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", locations+i);
    }
    std::sort(locations, locations+N);

    /*for (int i=0; i<N; i++) {
        printf("%d ", locations[i]);
    }
    printf("\n");*/

    int *qlower = new int[Q];
    int *qupper = new int[Q];
    for (int i=0; i<Q; i++) {
        fscanf(fileIn, "%d %d", qlower+i, qupper+i);
    }

    /*for (int i=0; i<N; i++) {
        printf("%d %d\n", qlower[i], qupper[i]);
    }*/

    for (int i=0; i<Q; i++) {
        int lower = bsearch(locations, qlower[i], 0, N-1);
        int upper = bsearch(locations, qupper[i], 0, N-1);
        if (locations[lower] == qlower[i]) {
            lower--;
        }
        printf("%d, %d:\t%d\n", lower, upper, upper-lower);
        fprintf(fileOut, "%d\n", upper-lower);
    }
}
