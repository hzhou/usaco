#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

struct cow {
    int x;
    int y;
};


int main(int argc, char** argv)
{
    int min_perimeter;
    int i_next;
    int i;
    int n_tmp;

    FILE* In = fopen("fenceplan.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    fscanf(In, " %d %d" ,&N,&M);
    struct cow cow_list[N];
    int A[M];
    int B[M];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&cow_list[i].x,&cow_list[i].y);
    }
    for (int  i = 0; i<M; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);
    std::vector<int> adj_list[N];
    for (int  i = 0; i<M; i++) {
        adj_list[A[i]].push_back(B[i]);
        adj_list[B[i]].push_back(A[i]);
    }
    min_perimeter = 1000000000;
    int Visited[N];
    for (int  i = 0; i<N; i++) {
        Visited[i] = 0;
    }
    i_next = 0;
    while (1) {
        while (Visited[i_next]) {
            i_next++;
            if (i_next == N) {
                goto done;
            }
        }
        std::vector<int> region;
        std::vector<int> stack;
        Visited[i_next] = 1;
        region.push_back(i_next);
        stack.push_back(i_next);
        while (stack.size() > 0) {
            i = stack.back();
            stack.pop_back();
            for(auto a : adj_list[i]){
                if (!Visited[a]) {
                    Visited[a] = 1;
                    region.push_back(a);
                    stack.push_back(a);
                }
            }
        }
        int x1 = 1000000000;
        int y1 = 1000000000;
        int x2 = 0;
        int y2 = 0;
        for(auto i : region){
            if (x1 > cow_list[i].x) {
                x1 = cow_list[i].x;
            }
            if (x2 < cow_list[i].x) {
                x2 = cow_list[i].x;
            }
            if (y1 > cow_list[i].y) {
                y1 = cow_list[i].y;
            }
            if (y2 < cow_list[i].y) {
                y2 = cow_list[i].y;
            }
        }
        n_tmp = (y2 - y1) * 2 + (x2 - x1) * 2;
        if (min_perimeter > n_tmp) {
            min_perimeter = n_tmp;
        }
    }
    done:
        FILE* Out = fopen("fenceplan.out", "w");
        fprintf(Out, "%d\n", min_perimeter);
        fclose(Out);
    return 0;
}
