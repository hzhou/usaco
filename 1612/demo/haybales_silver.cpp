#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int get_n(int *cows, int N, int a, int b);
int find_i(int *cows, int i1, int i2, int a);

int main(int argc, char** argv)
{
    int n;

    int N;
    int Q;
    FILE* In = fopen("haybales.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&Q);
    int cows[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&cows[i]);
    }
    std::sort(cows, cows+N, [&](int a, int b){
        return a < b;
    } );
    FILE* Out = fopen("haybales.out", "w");
    for (int  i = 0; i<Q; i++) {
        int a;
        int b;
        fscanf(In, " %d %d" ,&a,&b);
        n = get_n(cows, N, a, b);
        fprintf(Out, "%d\n", n);
    }
    fclose(Out);
    fclose(In);
    return 0;
}

int get_n(int *cows, int N, int a, int b)
{
    int i;
    int j;

    i = find_i(cows, 0, N - 1, a);
    j = find_i(cows, 0, N - 1, b);
    if (i > 0 && cows[i-1] == a) {
        i--;
    }
    return j - i;
}

int find_i(int *cows, int i1, int i2, int a)
{
    int i;

    while (i1 <= i2) {
        i = (i1 + i2) / 2;
        if (cows[i] > a) {
            i2 = i - 1;
        } else {
            i1 = i + 1;
        }
    }
    return i1;
}
