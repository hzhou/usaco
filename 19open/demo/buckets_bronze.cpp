#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

char grid[10*10+1];

int main(int argc, char** argv)
{
    int i_cur;
    int i;
    int j;

    FILE* In = fopen("buckets.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    for (int  i = 0; i<10; i++) {
        fscanf(In, "%s", &grid[i*10]);
    }
    fclose(In);
    int i_lake;
    for (int  i = 0; i<100; i++) {
        if (grid[i] == 'L') {
            i_lake = i;
        }
    }
    int dist_list[100];
    for (int  i = 0; i<100; i++) {
        dist_list[i] = 100;
    }
    dist_list[i_lake] = 0;
    int min_dist = 100;
    std::vector<int> stack;
    stack.push_back(i_lake);
    while (stack.size() > 0) {
        i_cur = stack.back();
        stack.pop_back();
        int adj_list[4];
        int n_adj = 0;
        i = i_cur / 10;
        j = i_cur % 10;
        if (i > 0) {
            adj_list[n_adj++] = i_cur - 10;
        }
        if (i < 9) {
            adj_list[n_adj++] = i_cur + 10;
        }
        if (j > 0) {
            adj_list[n_adj++] = i_cur - 1;
        }
        if (j < 9) {
            adj_list[n_adj++] = i_cur + 1;
        }
        for (int  i = 0; i<n_adj; i++) {
            if (grid[adj_list[i]] == 'B') {
                if (min_dist > dist_list[i_cur]) {
                    min_dist = dist_list[i_cur];
                }
            } else if (grid[adj_list[i]] == 'R') {
            } else if (dist_list[adj_list[i]] > dist_list[i_cur] + 1) {
                dist_list[adj_list[i]] = dist_list[i_cur] + 1;
                stack.push_back(adj_list[i]);
            }
        }
    }
    FILE* Out = fopen("buckets.out", "w");
    fprintf(Out, "%d\n", min_dist);
    fclose(Out);
    return 0;
}
