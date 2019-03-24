#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    int B;
    int m;
    FILE* In = fopen("balancing.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&B);
    int X[N];
    int Y[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&X[i],&Y[i]);
    }
    fclose(In);
    int M = N;
    {
        int A[N];
        int B[N];
        for(int  i=0; i<N; i++){
            A[i] = X[i] + 1;
            B[i] = Y[i] + 1;
        }
        std::sort(A, A + N);
        std::sort(B, B + N);
        for(int  ia=0; ia<N-1; ia++){
            for(int  ib=0; ib<N-1; ib++){
                int q1 = 0;
                int q2 = 0;
                int q3 = 0;
                int q4 = 0;
                for(int  i=0; i<N; i++){
                    if(X[i] < A[ia]){
                        if(Y[i] < B[ib]){
                            q1++;
                        }
                        else{
                            q2++;
                        }
                    }
                    else{
                        if(Y[i] < B[ib]){
                            q3++;
                        }
                        else{
                            q4++;
                        }
                    }
                }
                m = q1;
                if(m < q2){
                    m = q2;
                }
                if(m < q3){
                    m = q3;
                }
                if(m < q4){
                    m = q4;
                }
                if(M > m){
                    M = m;
                }
            }
        }
    }
    FILE* Out = fopen("balancing.out", "w");
    fprintf(Out, "%d\n", M);
    fclose(Out);
    return 0;
}

