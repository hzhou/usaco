#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int j;

    int L[9] = {5, 9, 1, 8, 2, 6, 4, 7, 3};
    printf("L[%d]: ", 9);
    for (int  _i = 0; _i<9; _i++) {
        printf("%d ", L[_i]);
    }
    puts("");
    int P[9];
    for (int  i = 0; i<9; i++) {
        P[i] = i;
    }
    std::sort(P, P+9, [&](int a, int b){
        return L[a] < L[b];
    } );
    printf("P[%d]: ", 9);
    for (int  _i = 0; _i<9; _i++) {
        printf("%d ", P[_i]);
    }
    puts("");
    int I[9];
    int C[9];
    for (int  i = 0; i<9; i++) {
        C[i] = 0;
    }
    for (int  i = 0; i<9; i++) {
        int sum = 0;
        j = P[i];
        if (j == 0) {
            sum = C[0];
        } else {
            while (j > 0) {
                sum += C[j];
                j -= j &- j;
            }
        }
        I[i] = P[i] - sum;
        j = P[i];
        while (j < 9) {
            C[j] += 1;
            if (j == 0) {
                j++;
            } else {
                j += j &- j;
            }
        }
    }
    printf("I[%d]: ", 9);
    for (int  _i = 0; _i<9; _i++) {
        printf("%d ", I[_i]);
    }
    puts("");
    return 0;
}
