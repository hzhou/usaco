#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    FILE* In = fopen("blocks.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    char A[N][11];
    char B[N][11];
    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s %s", A[i], B[i]);
    }
    fclose(In);
    printf("%s - %s\n", A[2], B[2]);
    int count[26] = {0};
    for (int  i = 0; i<N; i++) {
        int cnt_a[26] = {0};
        int cnt_b[26] = {0};
        for (int  j = 0; j<strlen(A[i]); j++) {
            cnt_a[(A[i][j]-'a')]++;
        }
        for (int  j = 0; j<strlen(B[i]); j++) {
            cnt_b[(B[i][j]-'a')]++;
        }
        for (int  j = 0; j<26; j++) {
            count[j] += std::max(cnt_a[j], cnt_b[j]);
        }
    }
    FILE* Out = fopen("blocks.out", "w");
    for (int  j = 0; j<26; j++) {
        fprintf(Out, "%d\n", count[j]);
    }
    fclose(Out);
    return 0;
}

