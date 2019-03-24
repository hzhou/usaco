#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int X;
    int Y;
    int M;
    int nY;
    int max;
    int n;
    FILE* In = fopen("pails.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&X,&Y,&M);
    fclose(In);
    nY = M / Y;
    max = 0;
    for(int  i=0; i<nY+1; i++){
        n = i * Y + (M - i * Y) / X * X;
        if(max < n){
            max = n;
        }
    }
    FILE* Out = fopen("pails.out", "w");
    fprintf(Out, "%d\n", max);
    fclose(Out);
    return 0;
}

