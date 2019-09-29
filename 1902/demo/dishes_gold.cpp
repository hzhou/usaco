#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

bool can(int M);

int *A;
int N;
int *P;

int main(int argc, char** argv)
{
    int i1;
    int i2;
    int i3;
    int i_ans;

    FILE* In = fopen("dishes.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    A = new int[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
        A[i]--;
    }
    fclose(In);
    P = new int[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        return A[a] < A[b];
    } );
    i1 = 1;
    i2 = N;
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        if (can(i3)) {
            i1 = i3 + 1;
        } else {
            i2 = i3 - 1;
        }
    }
    i_ans = i2;
    std::cout<<"i_ans="<<i_ans<<'\n';
    FILE* Out = fopen("dishes.out", "w");
    fprintf(Out, "%d\n", i_ans);
    fclose(Out);
    return 0;
}

bool can(int M)
{
    int j1;
    int j2;
    int j;

    std::vector<int> stacks[M];
    int i1 = 0;
    int i2 = 0;
    int i_finish = 0;
    while (P[i_finish] >= M) {
        i_finish++;
    }
    for (int  i = 0; i<M; i++) {
        if (i1 == i2) {
            stacks[i2].push_back(A[i]);
            i2++;
        } else if (A[i] > stacks[i2-1][0]) {
            stacks[i2].push_back(A[i]);
            i2++;
        } else {
            j1 = i1;
            j2 = i2;
            while (j1 <= j2) {
                j = (j1 + j2) / 2;
                if (A[i] > stacks[j][0]) {
                    j1 = j + 1;
                } else if (j > i1 && A[i] < stacks[j-1][0]) {
                    j2 = j - 1;
                } else if (A[i] < stacks[j].back()) {
                    stacks[j].push_back(A[i]);
                    break;
                } else {
                    return false;
                }
            }
        }
        while (1) {
            while (stacks[i1].size() > 0 && stacks[i1].back() == i_finish) {
                stacks[i1].pop_back();
                i_finish++;
                while (P[i_finish] >= M) {
                    i_finish++;
                }
            }
            if (stacks[i1].size() == 0) {
                i1++;
                if (i1 == i2) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return true;
}
