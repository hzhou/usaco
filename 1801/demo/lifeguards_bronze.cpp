#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

struct item {
	int t1;
	int t2;
};

bool cmp(item a, item b);

int main(int argc, char** argv){
    int N;
    FILE* In = fopen("lifeguards.in", "r");
    fscanf(In, " %d" ,&N);
    item L[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&L[i].t1,&L[i].t2);
    }
    sort(L, L + N, cmp);
    fclose(In);
    int g_max = 0;
    for(int  _i=0; _i<N; _i++){
        int l = 0;
        int t = L[0].t1;
        for(int  i=0; i<N; i++){
            if(i != _i){
                int t1 = L[i].t1;
                if(t1 < t){
                    t1 = t;
                }
                if(L[i].t2 > t){
                    t = L[i].t2;
                    l += t - t1;
                }
            }
        }
        if(g_max < l){
            g_max = l;
        }
    }
    FILE* Out = fopen("lifeguards.out", "w");
    fprintf(Out, "%d\n", g_max);
    fclose(Out);
    return 0;
}

bool cmp(item a, item b){
    return a.t1 < b.t1;
}

