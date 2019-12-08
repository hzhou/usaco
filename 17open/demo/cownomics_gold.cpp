#include <cstring>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int match(int j, int k);

char s_spotty[500][500];
char s_plain[500][500];
int N;
int M;

int main(int argc, char** argv)
{
    int i1;
    int i2;
    int i3;
    int tn_flag;
    int count;


    FILE* In = fopen("cownomics.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&M);
    for (int  i = 0; i<N; i++) {
        char s[M+1];
        fscanf(In, "%s", s);
        memcpy(s_spotty[i], s, M);
    }
    for (int  i = 0; i<N; i++) {
        char s[M+1];
        fscanf(In, "%s", s);
        memcpy(s_plain[i], s, M);
    }
    fclose(In);

    i1 = 1;
    i2 = M;
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        tn_flag = 0;
        for (int  j = 0; j<M; j++) {
            if (j + i3 <= M) {
                if (!match(j, i3)) {
                    tn_flag = 1;
                    break;
                }
            }
        }
        if (tn_flag) {
            i2 = i3 - 1;
        } else {
            i1 = i3 + 1;
        }
    }
    count = i1;
    std::cout<<"count="<<count<<'\n';

    FILE* Out = fopen("cownomics.out", "w");
    fprintf(Out, "%d\n", count);



    fclose(Out);
    return 0;
}

int match(int j, int k)
{
    std::set<std::string> S;
    for (int  i = 0; i<N; i++) {
        std::string s(s_spotty[i]+j, k);
        S.insert(s);
    }

    for (int  i = 0; i<N; i++) {
        std::string s(s_plain[i]+j, k);
        if (S.count(s) > 0) {
            return 1;
        }
    }
    return 0;
}
