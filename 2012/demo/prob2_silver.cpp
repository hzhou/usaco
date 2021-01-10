#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cstdio>
#include <cassert>
#include <algorithm>

struct pos {
    int x;
    int y;
};


int N;

int main(int argc, char** argv)
{
    int n_ret;
    struct pos *A;
    int *PSUM;
    long long count;

    n_ret = scanf(" %d" ,&N);
    assert(n_ret > 0);

    A=(struct pos*)malloc(N*sizeof(struct pos));

    for (int  i = 0; i<N; i++) {
        n_ret = scanf(" %d %d" ,&A[i].x,&A[i].y);
        assert(n_ret > 0);
    }

    std::sort(A, A+N, [&](struct pos a, struct pos b){
        return a.x < b.x;
    } );
    for (int  i = 0; i<N; i++) {
        A[i].x = i;
    }
    std::sort(A, A+N, [&](struct pos a, struct pos b){
        return a.y < b.y;
    } );
    for (int  i = 0; i<N; i++) {
        A[i].y = i;
    }

    PSUM=(int*)calloc(N*N, sizeof(int));
    for (int  i = 0; i<N; i++) {
        PSUM[A[i].x+(A[i].y)*N] = 1;
    }
    for (int  i = 1; i<N; i++) {
        PSUM[i+(0)*N] += PSUM[i-1+(0)*N];
        PSUM[0+(i)*N] += PSUM[0+(i-1)*N];
    }
    for (int  i = 1; i<N; i++) {
        for (int  j = 1; j<N; j++) {
            PSUM[i+(j)*N] += PSUM[i-1+(j)*N] + PSUM[i+(j-1)*N] - PSUM[i-1+(j-1)*N];
        }
    }

    count = 1 + N;
    for (int  i = 0; i<N; i++) {
        for (int  j = i+1; j<N; j++) {
            int x0;
            int x1;
            int y0;
            int y1;
            int n0;
            int n1;
            x0 = std::min(A[i].x, A[j].x);
            x1 = std::max(A[i].x, A[j].x);
            y0 = std::min(A[i].y, A[j].y);
            y1 = std::max(A[i].y, A[j].y);
            n0 = PSUM[x1+(y0)*N];
            if (x0 > 0) {
                n0 -= PSUM[x0-1+(y0)*N];
            }
            n1 = PSUM[x1+(N-1)*N] - PSUM[x0+(N-1)*N] - PSUM[x1+(y1)*N] + PSUM[x0+(y1)*N] + 1;
            count += n0 * n1;
        }
    }

    printf("%lld\n", count);
    return 0;
}
