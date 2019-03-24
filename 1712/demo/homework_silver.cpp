#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int *L;

int main(int argc, char** argv)
{
    int N;
    FILE* In = fopen("homework.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    L = new int[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&L[i]);
    }
    int idx_list[N];
    for (int  i = 0; i<N; i++) {
        idx_list[i] = i;
    }
    fclose(In);
    std::sort(idx_list, idx_list+N, [&](int a, int b){
        return L[a] < L[b];
    } );
    int sum = 0;
    for (int  i = 0; i<N; i++) {
        sum += L[i];
    }
    double max = 0;
    std::vector<int> max_list;
    int i0 = 0;
    int sum2 = 0;
    for (int  j = 0; j<N-2; j++) {
        sum2 += L[j];
        while (idx_list[i0] <= j) {
            i0++;
        }
        double t = sum-sum2-L[idx_list[i0]];
        t /= N - j - 2;
        if (max < t) {
            max = t;
            max_list.clear();
            max_list.push_back(j + 1);
        } else if (max == t) {
            max_list.push_back(j + 1);
        }
    }
    FILE* Out = fopen("homework.out", "w");
    for (int  i = 0; i<max_list.size(); i++) {
        fprintf(Out, "%d\n", max_list[i]);
    }
    fclose(Out);
    return 0;
}
