#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

struct item {
    int val;
    int val2;
    int idx;
};

int bin_search(item *A, int val);

int N;
int D;

int main(int argc, char** argv)
{
    int j;
    int i;

    FILE* In = fopen("piepie.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&D);
    auto A = new item[N];
    auto B = new item[N];
    for (int  i = 0; i<N; i++) {
        A[i].idx = i;
        fscanf(In, " %d %d" ,&A[i].val,&A[i].val2);
    }
    for (int  i = 0; i<N; i++) {
        B[i].idx = i;
        fscanf(In, " %d %d" ,&B[i].val2,&B[i].val);
    }
    fclose(In);
    std::sort(A, A+N, [&](item a, item b){
        return a.val2 < b.val2;
    } );
    std::sort(B, B+N, [&](item a, item b){
        return a.val2 < b.val2;
    } );
    auto R = new int[N*2];
    for (int  i = 0; i<N*2; i++) {
        R[i] = -1;
    }
    vector<int> *pool = new vector<int>;
    vector<int> *temp = new vector<int>;
    for (int  i = 0; i<N; i++) {
        if (A[i].val2 == 0) {
            j = A[i].idx;
            R[j] = 1;
            pool->push_back(i);
        } else {
            break;
        }
    }
    for (int  i = 0; i<N; i++) {
        if (B[i].val2 == 0) {
            j = B[i].idx;
            pool->push_back(i + N);
            R[j+N] = 1;
        } else {
            break;
        }
    }
    while (pool->size() > 0) {
        for(auto j : *pool){
            if (j < N) {
                int val = A[j].val;
                i = bin_search(B, val);
                while (i>=0 && val-B[i].val2<=D) {
                    if (R[B[i].idx+N] == -1) {
                        temp->push_back(i + N);
                        R[B[i].idx+N] = R[A[j].idx] + 1;
                    }
                    i--;
                }
            } else {
                int val = B[j-N].val;
                i = bin_search(A, val);
                while (i>=0 && val-A[i].val2<=D) {
                    if (R[A[i].idx] == -1) {
                        temp->push_back(i);
                        R[A[i].idx] = R[B[j-N].idx+N] + 1;
                    }
                    i--;
                }
            }
        }
        swap(pool, temp);
        temp->clear();
    }
    FILE* Out = fopen("piepie.out", "w");
    for (int  i = 0; i<N; i++) {
        fprintf(Out, "%d\n", R[i]);
    }
    fclose(Out);
    return 0;
}

int bin_search(item *A, int val)
{
    int i_0;
    int i_n;
    int i;

    i_0 = 0;
    i_n = N - 1;
    if (A[i_0].val2 > val) {
        return -1;
    }
    if (A[i_n].val2 <= val) {
        return i_n;
    }
    while (i_n > i_0 + 1) {
        i = (i_n + i_0) / 2;
        if (A[i].val2 > val) {
            i_n = i;
        } else {
            i_0 = i;
        }
    }
    return i_0;
}
