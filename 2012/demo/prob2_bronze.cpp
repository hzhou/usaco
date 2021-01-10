#include <cstdio>
#include <cstdio>
#include <cassert>
#include <algorithm>

int N;
int *A;

int main(int argc, char** argv)
{
    int n_ret;
    int count;
    int sum;
    int avg;
    int n;

    n_ret = scanf(" %d" ,&N);
    assert(n_ret > 0);
    A = new int[N];
    for (int  i = 0; i<N; i++) {
        n_ret = scanf(" %d" ,&A[i]);
        assert(n_ret > 0);
    }

    count = N;
    for (int  i = 0; i<N; i++) {
        sum = A[i];
        for (int  j = i+1; j<N; j++) {
            sum += A[j];
            n = j - i + 1;
            if (sum % n == 0) {
                avg = sum / n;
                for (int  k = i; k<j+1; k++) {
                    if (A[k] == avg) {
                        count++;
                        break;
                    }
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
