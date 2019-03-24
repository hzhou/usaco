/*
ID: usaco107
LANG: C++
PROG: ride
TASK: test
*/
#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int n_a;
    int n_b;

    char s_a[7];
    char s_b[7];
    FILE* In = fopen("ride.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, "%s %s", s_a, s_b);
    fclose(In);
    n_a = 1;
    for (int  i = 0; i<6; i++) {
        if (!s_a[i]) {
            break;
        }
        n_a *= s_a[i] - 'A' + 1;
    }
    n_a %= 47;
    n_b = 1;
    for (int  i = 0; i<6; i++) {
        if (!s_b[i]) {
            break;
        }
        n_b *= s_b[i] - 'A' + 1;
    }
    n_b %= 47;
    FILE* Out = fopen("ride.out", "w");
    if (n_a == n_b) {
        fprintf(Out, "GO\n");
    } else {
        fprintf(Out, "STAY\n");
    }
    fclose(Out);
    return 0;
}
