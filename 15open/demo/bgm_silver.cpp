#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

long long b[7];
long long e[7];
long long s[7];
long long i[7];
long long g[7];
long long o[7];
long long m[7];

int main(int argc, char** argv)
{
    FILE* In = fopen("bgm.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    for (int  ii = 0; ii<N; ii++) {
        char ss[2];
        int n;
        fscanf(In, "%s", ss);
        fscanf(In, " %d" ,&n);
        n = (n % 7 + 7) % 7;
        if (ss[0] == 'B') {
            b[n] += 1;
        } else if (ss[0] == 'E') {
            e[n] += 1;
        } else if (ss[0] == 'S') {
            s[n] += 1;
        } else if (ss[0] == 'I') {
            i[n] += 1;
        } else if (ss[0] == 'G') {
            g[n] += 1;
        } else if (ss[0] == 'O') {
            o[n] += 1;
        } else if (ss[0] == 'M') {
            m[n] += 1;
        }
    }
    fclose(In);
    long long count = 0;
    for (int  B = 0; B<7; B++) {
        if (b[B] == 0) {
            continue;
        }
        for (int  E = 0; E<7; E++) {
            if (e[E] == 0) {
                continue;
            }
            for (int  S = 0; S<7; S++) {
                if (s[S] == 0) {
                    continue;
                }
                for (int  I = 0; I<7; I++) {
                    if (i[I] == 0) {
                        continue;
                    }
                    for (int  G = 0; G<7; G++) {
                        if (g[G] == 0) {
                            continue;
                        }
                        for (int  O = 0; O<7; O++) {
                            if (o[O] == 0) {
                                continue;
                            }
                            for (int  M = 0; M<7; M++) {
                                if (m[M] == 0) {
                                    continue;
                                }
                                if ((B + E + S + S + I + E) % 7 == 0 || (G + O + E + S) % 7 == 0 || (M + O + O) % 7 == 0) {
                                    count += b[B] * e[E] * s[S] * i[I] * g[G] * o[O] * m[M];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("bgm.out", "w");
    fprintf(Out, "%lld\n", count);
    fclose(Out);
    return 0;
}
