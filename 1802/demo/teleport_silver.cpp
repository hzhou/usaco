#include <cstdio>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main(int argc, char** argv)
{
    FILE* In = fopen("teleport.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int A[N];
    int B[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
    }
    fclose(In);
    long long sum = 0;
    for (int  i = 0; i<N; i++) {
        sum += abs(B[i] - A[i]);
    }
    map<int, int> slope;
    for (int  i = 0; i<N; i++) {
        int l = abs(A[i]-B[i]);
        if (abs(A[i]) >= l) {
        } else {
            int d = l-abs(A[i]);
            slope[B[i]-d] += 1;
            slope[B[i]] -= 2;
            slope[B[i]+d] += 1;
        }
    }
    long long min_sum = sum;
    int a = 0;
    int x;
    for(auto it : slope){
        if (a != 0) {
            sum -= (long long) a * (it.first - x);
            if (min_sum > sum) {
                min_sum = sum;
            }
        }
        x = it.first;
        a += it.second;
    }
    std::cout<<"min_sum="<<min_sum<<'\n';
    FILE* Out = fopen("teleport.out", "w");
    fprintf(Out, "%lld\n", min_sum);
    fclose(Out);
    return 0;
}
