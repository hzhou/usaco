#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct T {
	int i;
	int a;
	int t;
};


int main(int argc, char** argv)
{
    int i;

    int N;
    FILE* In = fopen("convention2.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    T cows[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&cows[i].a,&cows[i].t);
        cows[i].i = i;
    }
    fclose(In);
    std::sort(cows, cows+N, [&](T a, T b){
        return a.a < b.a;
    } );
    int max = 0;
    int t = cows[0].a+cows[0].t;
    i = 1;
    while (i < N) {
        while (cows[i].t == 0) {
            i++;
        }
        int min_i = N;
        int min_j = 0;
        for (int  j = i; j<N; j++) {
            if (cows[j].a > t) {
                break;
            }
            if (cows[j].t == 0) {
                continue;
            }
            if (min_i > cows[j].i) {
                min_i = cows[j].i;
                min_j = j;
            }
        }
        if (min_j == 0) {
            t = cows[i].a + cows[i].t;
            cows[i].t = 0;
        } else {
            if (max < t - cows[min_j].a) {
                max = t - cows[min_j].a;
            }
            t += cows[min_j].t;
            cows[min_j].t = 0;
        }
    }
    std::cout<<"max="<<max<<'\n';
    FILE* Out = fopen("convention2.out", "w");
    fprintf(Out, "%d\n", max);
    fclose(Out);
    return 0;
}
