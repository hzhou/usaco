#include <vector>
#include <cstdio>
#include <cstdio>
#include <cassert>
#include <algorithm>

int N;
char *grid;

int main(int argc, char** argv)
{
    int n_ret;
    int i_next;
    int k;
    int i;
    int j;

    FILE* In = fopen("perimeter.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    n_ret = fscanf(In, " %d" ,&N);
    assert(n_ret > 0);
    grid = new char[N*N+1];
    for (int  i = 0; i<N; i++) {
        n_ret = fscanf(In, "%s", grid + i * N);
        assert(n_ret > 0);
    }
    fclose(In);

    std::vector<std::pair<int,int> > region_list;
    int cache[N*N];
    for (int  i = 0; i<N*N; i++) {
        if (grid[i] == '#') {
            cache[i] = 1;
        } else {
            cache[i] = 0;
        }
    }

    i_next = 0;
    while (1) {
        while (i_next < N * N && cache[i_next] == 0) {
            i_next++;
        }
        if (i_next >= N * N) {
            break;
        }

        int area = 0;
        int perimeter = 0;

        std::vector<int> stack;
        stack.push_back(i_next);
        cache[i_next] = 0;

        while (stack.size() > 0) {
            k = stack.back();
            stack.pop_back();

            area++;

            i = k / N;
            j = k % N;

            int P[4];
            int n = 0;

            if (i > 0) {
                P[n++] = k - N;
            }
            if (i + 1 < N) {
                P[n++] = k + N;
            }
            if (j > 0) {
                P[n++] = k - 1;
            }
            if (j + 1 < N) {
                P[n++] = k + 1;
            }
            perimeter += 4 - n;
            for (int  i = 0; i<n; i++) {
                j = P[i];
                if (grid[j] == '.') {
                    perimeter++;
                } else if (cache[j]) {
                    cache[j] = 0;
                    stack.push_back(j);
                }
            }
        }
        region_list.push_back({area, perimeter});
    }

    int max_area = 0;
    int min_perimeter;
    for(auto it : region_list){
        if (max_area < it.first) {
            max_area = it.first;
            min_perimeter = it.second;
        } else if (max_area == it.first) {
            if (min_perimeter > it.second) {
                min_perimeter = it.second;
            }
        }
    }

    FILE* Out = fopen("perimeter.out", "w");
    fprintf(Out, "%d %d\n", max_area, min_perimeter);
    fclose(Out);
    return 0;
}
