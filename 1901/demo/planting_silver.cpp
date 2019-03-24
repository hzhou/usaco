#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int i;

    FILE* In = fopen("planting.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int A[N-1];
    int B[N-1];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);
    std::vector<int> adj_list[N];
    for (int  i = 0; i<N-1; i++) {
        adj_list[A[i]].push_back(B[i]);
        adj_list[B[i]].push_back(A[i]);
    }
    int pointer_list[N];
    for (int  i = 0; i<N; i++) {
        pointer_list[i] = i;
    }
    int count_list[N];
    for (int  i = 0; i<N; i++) {
        count_list[i] = 0;
    }
    std::vector<int> stack;
    stack.push_back(0);
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();
        count_list[i]++;
        if (pointer_list[i] != i) {
            count_list[pointer_list[i]]++;
        }
        for(auto j : adj_list[i]){
            if (j != pointer_list[i]) {
                printf("%d> %d\n", i, j);
                pointer_list[j] = i;
                stack.push_back(j);
            }
        }
    }
    int count_max = count_list[0];
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
