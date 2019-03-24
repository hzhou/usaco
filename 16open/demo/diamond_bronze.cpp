#include <cstdio>
#include <cstdio>
#include <algorithm>

int binary_search(int * L, int i);

int N;
int K;

int main(int argc, char** argv){
    int i_next;
     j_next;
    FILE* In = fopen("diamond.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&K);
    int L[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&L[i]);
    }
    fclose(In);
    std::sort(L, L+N, [&](int a, int b){
        return a < b;
    } );
    int max = 1;
    for(int  i=0; i<N; i++){
        int count;
        i_next = binary_search(L, i);
        count = i_next - i;
        for(int  j=i_next; j<N; j++){
            j_next = binary_search(L, j);
            if(max < count + j_next - j){
                max = count + j_next - j;
            }
        }
    }
    FILE* Out = fopen("diamond.out", "w");
    fprintf(Out, "%d\n", max);
    fclose(Out);
    return 0;
}

int binary_search(int * L, int i){
    int i1;
    int i2;
    int i3;
    int t = L[i];
    i1 = i;
    i2 = N - 1;
    if(L[N-1] - t <= K){
        return N;
    }
    while(i1 <= i2){
        i3 = (i1 + i2) / 2;
        if(L[i3] - t <= K){
            i1 = i3 + 1;
        }
        else{
            i2 = i3 - 1;
        }
    }
    return i1;
}

