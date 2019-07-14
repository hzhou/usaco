#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int *A;
int N;

int main(int argc, char** argv)
{
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
    std::vector<int> stacks[N];
    int i1 = 0;
    int i2 = 0;
    int i_clean = -1;
    for (int  i = 0; i<N; i++) {
        if (A[i] < i_clean) {
            i_ans = i;
            goto done;
        }
        if (i1 == i2) {
            stacks[i2].push_back(A[i]);
            i2++;
        } else if (A[i] > stacks[i2-1][0]) {
            stacks[i2].push_back(A[i]);
            i2++;
        } else {
            for (int  j = i1; j<i2; j++) {
                if (A[i] < stacks[j][0]) {
                    if (A[i] > stacks[j].back()) {
                        for (int  j2 = i1; j2<j+1; j2++) {
                            while (stacks[j2].size() > 0 && stacks[j2].back() < A[i]) {
                                if (i_clean < stacks[j2].back()) {
                                    i_clean = stacks[j2].back();
                                } else {
                                    i_ans = i;
                                    goto done;
                                }
                                stacks[j2].pop_back();
                            }
                        }
                        i1 = j;
                    }
                    stacks[j].push_back(A[i]);
                    break;
                } else {
                    continue;
                }
            }
        }
    }
    done:
    std::cout<<"i_ans="<<i_ans<<'\n';
    FILE* Out = fopen("dishes.out", "w");
    fprintf(Out, "%d\n", i_ans);
    fclose(Out);
    return 0;
}
