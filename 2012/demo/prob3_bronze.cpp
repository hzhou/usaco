#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdio>
#include <climits>
#include <cassert>
#include <algorithm>
#include <stdint.h>

struct cow {
    char s[2];
    int x;
    int y;
    int n;
};

struct stop {
    int i;
    int j;
    int n;
};


int N;

int main(int argc, char** argv)
{
    int n_ret;
    struct cow *A;
    int tn_ret;
    std::vector<stop> stop_list;
    int n_i;
    int n_j;
    int n;
    int i2;
    int j2;
    int16_t n2;

    n_ret = scanf(" %d" ,&N);
    assert(n_ret > 0);
    A=(struct cow*)malloc(N*sizeof(struct cow));
    for (int  i = 0; i<N; i++) {
        tn_ret = scanf("%s %d %d", A[i].s, &A[i].x, &A[i].y);
        assert(tn_ret == 3);
        A[i].n = INT_MAX;
    }

    for (int  i = 0; i<N; i++) {
        for (int  j = i+1; j<N; j++) {
            if (A[i].s[0] == A[j].s[0]) {
                continue;
            }
            if (A[i].s[0] == 'E' && A[j].x > A[i].x && A[i].y > A[j].y) {
                n_i = A[j].x - A[i].x;
                n_j = A[i].y - A[j].y;
            } else if (A[i].s[0] == 'N' && A[j].y > A[i].y && A[i].x > A[j].x) {
                n_i = A[j].y - A[i].y;
                n_j = A[i].x - A[j].x;
            } else {
                continue;
            }

            if (n_i == n_j) {
                continue;
            }

            n = std::max(n_i, n_j);
            if (n_i == n) {
                stop_list.push_back((struct stop) {i, j, n});
            } else {
                stop_list.push_back((struct stop) {j, i, n});
            }
        }
    }

    std::sort(begin(stop_list), end(stop_list), [&](struct stop a, struct stop b){
        return a.n < b.n;
    } );

    for (int  i = 0; i<stop_list.size(); i++) {
        if (stop_list[i].n < 0) {
            continue;
        }
        A[stop_list[i].i].n = stop_list[i].n;
        for (int  j = i+1; j<stop_list.size(); j++) {
            if (stop_list[j].i == stop_list[i].i) {
                stop_list[j].n = -1;
            }
        }
        for (int  j = i+1; j<stop_list.size(); j++) {
            if (stop_list[j].j == stop_list[i].i) {
                i2 = stop_list[j].i;
                j2 = stop_list[j].j;
                n2 = stop_list[j].n;
                if (A[i2].s[0] == 'E' && A[i2].y > A[j2].y + A[j2].n) {
                    stop_list[j].n = -1;
                }
                if (A[i2].s[0] == 'N' && A[i2].x > A[j2].x + A[j2].n) {
                    stop_list[j].n = -1;
                }
            }
        }
    }

    for (int  i = 0; i<N; i++) {
        if (A[i].n == INT_MAX) {
            puts("Infinity");
        } else {
            printf("%d\n", A[i].n);
        }
    }
    return 0;
}
