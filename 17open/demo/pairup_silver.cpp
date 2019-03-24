#include <cstdio>
#include <cstdio>
#include <algorithm>

struct Cows {
	int count;
	int milk;
};


int main(int argc, char** argv){
    int i1;
    int i2;
    FILE* In = fopen("pairup.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    struct Cows A[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&A[i].count,&A[i].milk);
    }
    fclose(In);
    std::sort(A, A+N, [&](Cows a, Cows b){
        return a.milk < b.milk;
    } );
    int Max = 0;
    i1 = 0;
    i2 = N - 1;
    while(i1 <= i2){
        int t = A[i1].milk+A[i2].milk;
        if(Max < t){
            Max = t;
        }
        if(A[i1].count == A[i2].count){
            i1++;
            i2--;
        }
        else if(A[i1].count > A[i2].count){
            A[i1].count -= A[i2].count;
            i2--;
        }
        else if(A[i2].count > A[i1].count){
            A[i2].count -= A[i1].count;
            i1++;
        }
    }
    FILE* Out = fopen("pairup.out", "w");
    fprintf(Out, "%d\n", Max);
    fclose(Out);
    return 0;
}

