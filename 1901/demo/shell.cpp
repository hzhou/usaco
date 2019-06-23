#include <cstdio>
#include <cstdlib>

int main(){
    FILE * In = fopen("shell.in", "r");
    int N;
    fscanf(In, "%d", &N);
    int A[N], B[N], G[N];
    for(int i=0; i<N; i++){
        fscanf(In, "%d %d %d", &A[i], &B[i], &G[i]);
    }
    fclose(In);
    printf("G[1] = %d\n", G[1]);
    // -------------------
    int max_points= 0;
    for(int i_egg = 0; i_egg<3; i_egg++){
        int egg = i_egg;
        int win=0;
        for(int i=0; i< N; i++){
            if (egg==a){
                egg = b;
            }
            else if(egg==b){
                egg = a;
            }
            if (g==egg){
                win++;
            }
        }
        if (max_points < win){
            max_points = win;
        }
    }
    // -------------------
    FILE *Out =fopen("shell.out", "w");
    fprintf(Out,"%d\n",  max_points);
    fclose(Out);
    return 0;
}

