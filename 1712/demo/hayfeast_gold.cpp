#include <cstdio>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

using namespace std;

int main(int argc, char** argv)
{
    FILE* In = fopen("hayfeast.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    long long M;
    fscanf(In, "%d %lld", &N, &M);
    int F[N];
    int S[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&F[i],&S[i]);
    }
    fclose(In);
    int i_0 = 0;
    int i_1 = 0;
    long long sum = 0;
    map<int, int > maxes;
    while (sum < M && i_1 < N) {
        sum += F[i_1];
        if (maxes.count(S[i_1])) {
            maxes[S[i_1]]++;
        } else {
            maxes[S[i_1]] = 1;
        }
        i_1++;
    }
    int g_min = maxes.rbegin()->first;
    while (i_1 < N) {
        while (sum >= M) {
            sum -= F[i_0];
            if (maxes.count(S[i_0])) {
                if (maxes[S[i_0]] == 1) {
                    maxes.erase(S[i_0]);
                } else {
                    maxes[S[i_0]]--;
                }
            }
            i_0++;
        }
        while (sum < M) {
            sum += F[i_1];
            if (maxes.count(S[i_1])) {
                maxes[S[i_1]]++;
            } else {
                maxes[S[i_1]] = 1;
            }
            i_1++;
        }
        if (g_min > maxes.rbegin()->first) {
            g_min = maxes.rbegin()->first;
        }
    }
    FILE* Out = fopen("hayfeast.out", "w");
    fprintf(Out, "%d\n", g_min);
    fclose(Out);
    return 0;
}
