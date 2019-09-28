#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int a;

    FILE* In = fopen("revegetate.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    fscanf(In, " %d %d" ,&N,&M);
    int A[M];
    int B[M];
    int is_S[M];
    for (int  i = 0; i<M; i++) {
        char s[2];
        fscanf(In, "%s", s);
        if (s[0] == 'S') {
            is_S[i] = 1;
        } else {
            is_S[i] = 0;
        }
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);
    std::vector<int> *edge_list = new std::vector<int>[N];
    for (int  i = 0; i<M; i++) {
        edge_list[A[i]].push_back(i);
        edge_list[B[i]].push_back(i);
    }
    int *cache = new int[N];
    for (int  i = 0; i<N; i++) {
        cache[i] = 0;
    }
    int region_cnt = 0;
    std::vector<int> stack;
    int i_next = 0;
    while (1) {
        while (i_next < N && cache[i_next]) {
            i_next++;
        }
        if (i_next >= N) {
            break;
        }
        region_cnt++;
        stack.push_back(i_next);
        cache[i_next] = 1;
        while (stack.size() > 0) {
            a = stack.back();
            stack.pop_back();
            for(auto edge : edge_list[a]){
                int b = A[edge];
                if (a == b) {
                    b = B[edge];
                }
                int color;
                if (is_S[edge]) {
                    color = cache[a];
                } else {
                    color = 3 - cache[a];
                }
                if (!cache[b]) {
                    stack.push_back(b);
                    cache[b] = color;
                } else if (cache[b] != color) {
                    region_cnt = -1;
                    goto answer;
                }
            }
        }
    }
    answer:
    FILE* Out = fopen("revegetate.out", "w");
    if (region_cnt > 0) {
        fprintf(Out, "1");
        for (int  i = 0; i<region_cnt; i++) {
            fprintf(Out, "0");
        }
        fprintf(Out, "\n");
    } else {
        fprintf(Out, "0\n");
    }
    fclose(Out);
    return 0;
}
