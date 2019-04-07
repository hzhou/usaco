#include <cstdio>
#include <cstdio>
#include <algorithm>

int b[7];
int e[7];
int s[7];
int i[7];
int g[7];
int o[7];
int m[7];

int main(int argc, char** argv)
{
    FILE* In = fopen("bgm.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    for (int  i = 0; i<N; i++) {
        char s[2];
        int n;
        fscanf(In, "%s", s);
        fscanf(In, " %d" ,&n);
        n = (n % 7 + 7) % 7;
        if (s[0] == 'B') {
            b[n] += 1;
        } else if (s[0] == 'E') {
            e[n] += 1;
        } else if (s[0] == 'S') {
            s[n] += 1;
        } else if (s[0] == 'I') {
            i[n] += 1;
        } else if (s[0] == 'G') {
            g[n] += 1;
        } else if (s[0] == 'O') {
            o[n] += 1;
        } else if (s[0] == 'M') {
            m[n] += 1;
        }
    }
    fclose(In);
    long long count = 0;
    for (int  B = 0; B<7; B++) {
        if (b[B] == 0) {
            next;
        }
        for (int  E = 0; E<7; E++) {
            if (e[E] == 0) {
                next;
            }
            for (int  S = 0; S<7; S++) {
                if (s[S] == 0) {
                    next;
                }
                for (int  I = 0; I<7; I++) {
                    if (i[I] == 0) {
                        next;
                    }
                    for (int  G = 0; G<7; G++) {
                        if (g[G] == 0) {
                            next;
                        }
                        for (int  O = 0; O<7; O++) {
                            if (o[O] == 0) {
                                next;
                            }
                            for (int  M = 0; M<7; M++) {
                                if (m[M] == 0) {
                                    next;
                                }
                                if ((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O) % 7 == 0) {
                                    count += b[B] * e[E] * s[S] * i[I] * g[G] * o[O] * m[M];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    FILE* Out = fopen("bgm.out", "w");
    fprintf(Out, "%lld\n", count);
    fclose(Out);
    return 0;
}
