#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    int k;
    int j;
    int i_city;
    int k2;


    int N;
    FILE* In = fopen("citystate.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);

    char A[N][11];
    char B[N][3];

    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s %s", A[i], B[i]);
    }
    fclose(In);

    int M = 26*26;
    int cnt[26*26] = {0};
    for (int  i = 0; i<N; i++) {
        n = (B[i][0] - 'A') * 26 + (B[i][1] - 'A');
        cnt[n]++;
    }
    int idx[26*26];
    k = 0;
    for (int  i = 0; i<26*26; i++) {
        idx[i] = k;
        k += cnt[i];
    }

    int off[26*26] = {0};
    int L[N];
    for (int  i = 0; i<N; i++) {
        n = (B[i][0] - 'A') * 26 + (B[i][1] - 'A');
        j = idx[n] + off[n];
        L[j] = i;
        off[n]++;
    }
    int total_count = 0;
    for (int  i = 0; i<26*26; i++) {
        for (int  j = 0; j<cnt[i]; j++) {
            k = L[idx[i]+j];
            i_city = (A[k][0] - 'A') * 26 + (A[k][1] - 'A');
            if (i_city > i) {
                for (int  j2 = 0; j2<cnt[i_city]; j2++) {
                    k2 = L[idx[i_city]+j2];
                    if ((A[k2][0] - 'A') * 26 + (A[k2][1] - 'A') == i) {
                        total_count++;
                    }
                }
            }
        }
    }
    FILE* Out = fopen("citystate.out", "w");
    fprintf(Out, "%d\n", total_count);
    fclose(Out);
    return 0;
}
