#include <cstdio>
#include <queue>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int n;
    int i;

    FILE* In = fopen("moocast.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int x_list[N];
    int y_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&x_list[i],&y_list[i]);
    }
    fclose(In);

    int M[N*N];
    for (int  i = 0; i<N; i++) {
        for (int  j = i+1; j<N; j++) {
            n = (x_list[i] - x_list[j]) * (x_list[i] - x_list[j]) + (y_list[i] - y_list[j]) * (y_list[i] - y_list[j]);
            M[i*N+j] = n;
            M[j*N+i] = n;
        }
    }

    int L[N] = {0};

    int visited[N] = {0};
    auto cmp_fn = [&](int a, int b) {
        if (L[b] == 0) {
            return false;
        } else if (L[a] == 0) {
            return true;
        } else {
            return L[a] > L[b];
        }
    };

    std::priority_queue<int, std::vector<int>, decltype(cmp_fn)> stack(cmp_fn);
    stack.push(0);
    while (stack.size() > 0) {
        i = stack.top();
        stack.pop();
        if (visited[i]) {
            continue;
        } else {
            visited[i] = 1;
        }
        for (int  j = 0; j<N; j++) {
            if (j != i) {
                int t = L[i];
                if (t < M[i*N+j]) {
                    t = M[i*N+j];
                }
                if (L[j] == 0 || L[j] > t) {
                    L[j] = t;
                    stack.push(j);
                }
            }
        }
    }
    int n_max = 0;
    for (int  i = 0; i<N; i++) {
        if (n_max < L[i]) {
            n_max = L[i];
        }
    }
    FILE* Out = fopen("moocast.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}
