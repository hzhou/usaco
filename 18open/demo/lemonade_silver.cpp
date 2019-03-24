#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    FILE* In = fopen("lemonade.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int cows[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&cows[i]);
    }
    fclose(In);
    std::sort(cows, cows+N, [](int a, int b){
        return a < b;
    } );
    int i = 0;
    while(i < N && cows[i] < N - 1 - i){
        i++;
    }
    int cnt = N-i;
    printf("%d\n", cnt);
    FILE* Out = fopen("lemonade.out", "w");
    fprintf(Out, "%d\n", cnt);
    fclose(Out);
    return 0;
}

