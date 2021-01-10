#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int find_solution();

int N;
int B;
int *D;
int *s;
int *d;
int i_max = 0;

int main(int argc, char** argv)
{
    int n;

    FILE* In = fopen("snowboots.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&B);

    D = new int[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&D[i]);
    }

    s = new int[B];
    d = new int[B];
    for (int  i = 0; i<B; i++) {
        fscanf(In, " %d %d" ,&s[i],&d[i]);
    }
    fclose(In);

    n = find_solution();
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("snowboots.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

int find_solution()
{
    int i;


    for (int  j = 0; j<B; j++) {
        i = i_max;
        if (D[i] > s[j]) {
            continue;
        }

        while (1) {
            int k_max = 0;
            for (int  k = 1; k <= d[j]; k++) {
                if (i + k == N - 1) {
                    return j;
                }
                if (D[i+k] <= s[j]) {
                    k_max = k;
                }
            }
            if (k_max) {
                i += k_max;
                if (i_max < i) {
                    i_max = i;
                }
            } else {
                break;
            }
        }
    }
    return B;
}
