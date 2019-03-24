#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct cow {
    int x;
    int y;
    int p;
};

int get_Reach(int i);

int N;
int M[200][200];

int main(int argc, char** argv)
{
    int n_max;
    int n;

    FILE* In = fopen("moocast.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    struct cow cows[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d %d" ,&cows[i].x,&cows[i].y,&cows[i].p);
    }
    fclose(In);
    std::cout<<"N="<<N<<'\n';
    for (int  i = 0; i<N; i++) {
        for (int  j = 0; j<N; j++) {
            if ((cows[i].x - cows[j].x) * (cows[i].x - cows[j].x) + (cows[i].y - cows[j].y) * (cows[i].y - cows[j].y) <= cows[i].p * cows[i].p) {
                M[i][j] = 1;
            } else {
                M[i][j] = 0;
            }
        }
    }
    n_max = 0;
    for (int  i = 0; i<N; i++) {
        n = get_Reach(i);
        if (n_max < n) {
            n_max = n;
        }
    }
    std::cout<<"n_max="<<n_max<<'\n';
    FILE* Out = fopen("moocast.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}

int get_Reach(int i)
{
    int count;

    count = 0;
    int L[N];
    for (int  i = 0; i<N; i++) {
        L[i] = 0;
    }
    std::vector<int> stack;
    stack.push_back(i);
    L[i] = 1;
    count++;
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();
        for (int  j = 0; j<N; j++) {
            if (M[i][j]) {
                if (L[j] == 0) {
                    stack.push_back(j);
                    L[j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}
