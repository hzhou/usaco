#include <cstdio>
#include <set>
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
    int L[N];
    for (int  i = 0; i<N; i++) {
        L[i] = 0;
    }
    std::set<int> stack;
    stack.insert(0);
    while (stack.size() > 0) {
        auto it=stack.begin();
        i = *it;
        stack.erase(it);
        for (int  j = 0; j<N; j++) {
            if (j != i) {
                int t = L[i];
                if (t < M[i*N+j]) {
                    t = M[i*N+j];
                }
                if (L[j] == 0 || L[j] > t) {
                    L[j] = t;
                    stack.insert(j);
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
