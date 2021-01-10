#include <vector>
#include <cstdio>
#include <cstdio>
#include <cassert>
#include <algorithm>

int N;

int main(int argc, char** argv)
{
    int n_ret;
    int i;

    FILE* In = fopen("planting.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    n_ret = fscanf(In, " %d" ,&N);
    assert(n_ret > 0);
    int A[N-1];
    int B[N-1];
    for (int  i = 0; i<N-1; i++) {
        n_ret = fscanf(In, " %d %d" ,&A[i],&B[i]);
        assert(n_ret > 0);
        A[i]--;
        B[i]--;
    }
    fclose(In);

    int count_list[N];
    for (int  i = 0; i<N; i++) {
        count_list[i] = 0;
    }

    std::vector<int> adj_list[N];
    for (int  i = 0; i<N-1; i++) {
        adj_list[A[i]].push_back(B[i]);
        adj_list[B[i]].push_back(A[i]);
    }

    int pointer_list[N];
    for (int  i = 0; i<N; i++) {
        pointer_list[i] = i;
    }
    std::vector<int> stack;
    stack.push_back(0);
    count_list[0]--;
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();

        count_list[i]++;
        if (pointer_list[i] != i) {
            count_list[pointer_list[i]]++;
        }

        for(auto j : adj_list[i]){
            if (j != pointer_list[i]) {
                pointer_list[j] = i;
                stack.push_back(j);
            }
        }
    }

    int count_max = count_list[0]+1;
    for (int  i = 1; i<N; i++) {
        if (count_max < count_list[i] + 1) {
            count_max = count_list[i] + 1;
        }
    }

    FILE* Out = fopen("planting.out", "w");
    fprintf(Out, "%d\n", count_max);
    fclose(Out);
    return 0;
}
