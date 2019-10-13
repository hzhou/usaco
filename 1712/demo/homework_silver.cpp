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
    fclose(In);
    std::vector<int> max_list;
    double max = 0;
    int sum = L[N-1];
    int min = L[N-1];
    for (int  j = N-2; j >= 1; j--) {
        sum += L[j];
        if (min > L[j]) {
            min = L[j];
        }
        double t = sum-min;
        t /= N - (j) - 1;
        if (max < t) {
            max = t;
            max_list.clear();
            max_list.push_back(j);
        } else if (max == t) {
            max_list.push_back(j);
        }
    }
    FILE* Out = fopen("homework.out", "w");
    for (int  i = max_list.size()-1; i >= 0; i--) {
        fprintf(Out, "%d\n", max_list[i]);
    }
    fclose(Out);
    return 0;
}
