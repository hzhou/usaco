#include <cstring>
#include <cstdio>
#include <cstdio>
#include <algorithm>

struct sensor {
    int type;
    int lo;
    int hi;
};


int main(int argc, char** argv)
{
    FILE* In = fopen("traffic.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    struct sensor A[N];
    for (int  i = 0; i<N; i++) {
        char s[5];
        fscanf(In, "%s %d %d", s, &A[i].lo, &A[i].hi);
        if (strcmp(s, "on") == 0) {
            A[i].type = 1;
        } else if (strcmp(s, "off") == 0) {
            A[i].type = 2;
        } else {
            A[i].type = 0;
        }
    }
    fclose(In);
    int a1 = 0;
    int b1 = 1000;
    int a2 = 0;
    int b2 = 1000;
    int lo_in = 0;
    int hi_in = 0;
    int lo_out = 0;
    int hi_out = 0;
    for (int  i = 0; i<N; i++) {
        if (A[i].type == 1) {
            lo_in += A[i].lo;
            hi_in += A[i].hi;
            a2 += A[i].lo;
            b2 += A[i].hi;
        } else if (A[i].type == 2) {
            lo_out += A[i].lo;
            hi_out += A[i].hi;
            a2 -= A[i].hi;
            b2 -= A[i].lo;
            if (a2 < 0) {
                a2 = 0;
            }
            if (b2 < 0) {
                b2 = 0;
            }
        } else if (A[i].type == 0) {
            int a = A[i].lo + lo_out - hi_in;
            int b = A[i].hi + hi_out - lo_in;
            if (a1 < a) {
                a1 = a;
            }
            if (b1 > b) {
                b1 = b;
            }
            if (a2 < A[i].lo) {
                a2 = A[i].lo;
            }
            if (b2 > A[i].hi) {
                b2 = A[i].hi;
            }
        }
    }
    FILE* Out = fopen("traffic.out", "w");
    fprintf(Out, "%d %d\n", a1, b1);
    fprintf(Out, "%d %d\n", a2, b2);
    fclose(Out);
    return 0;
}
