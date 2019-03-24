#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <set>
#include <map>

typedef std::pair<int,int> ipair;

int sum(int *BIT, int N, int i) {
    i++;
    int sum = 0;
    for (; i>0; i -= i&-i) {
        sum += BIT[i];
    }
    return sum;
}
void increment(int *BIT, int N, int i) {
    i++;
    for (; i<=N; i += i&-i) {
        BIT[i]++;
    }
}

int main() {
    FILE *fileIn = fopen("sort.in", "r");
    FILE *fileOut = fopen("sort.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);
    ipair *A = new ipair[N];
    for (int i=0; i<N; i++) {
        int x;
        fscanf(fileIn, "%d", &x);
        A[i] = std::make_pair(x, i);
    }

    std::sort(A, A+N);

    int *BIT = new int[N+1];

    int ans = 0;
    for (int i=0; i<N-1; i++) {
        increment(BIT, N, A[i].second);
        int swaps = i+1 - sum(BIT, N, i);
        if (swaps>ans) {
            ans = swaps;
        }
    }
    ans = std::max(1, ans);

    printf("%d\n", ans);
    fprintf(fileOut, "%d\n", ans);
}
