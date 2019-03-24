#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    int K;
    FILE* In = fopen("bcs.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&K);
    char G[N*N*(K+1)+1];
    for(int  i=0; i<N*(K+1); i++){
        fscanf(In, "%s", G + i * N);
    }
    for(int  k=0; k<N*N*(K+1); k++){
        if(G[k] == '#'){
            G[k] = 1;
        }
        else{
            G[k] = 0;
        }
    }
    fclose(In);
    int x1;
    int x2;
    int y1;
    int y2;
    x1 = N - 1;
    x2 = 0;
    y1 = N - 1;
    y2 = 0;
    for(int  kx=0; kx<N; kx++){
        for(int  ky=0; ky<N; ky++){
            if(G[ky*N+kx]){
                if(x1 > kx){
                    x1 = kx;
                }
                if(x2 < kx){
                    x2 = kx;
                }
                if(y1 > ky){
                    y1 = ky;
                }
                if(y2 < ky){
                    y2 = ky;
                }
            }
        }
    }
    int Gx1 = x1;
    int Gx2 = x2;
    int Gy1 = y1;
    int Gy2 = y2;
    for(int  i=1; i<=K; i++){
        for(int  j=1; j<=K; j++){
            for(int  i_off_x=0; i_off_x<N; i_off_x++){
                for(int  i_off_y=0; i_off_y<N; i_off_y++){
                    for(int  j_off_x=0; j_off_x<N; j_off_x++){
                        for(int  j_off_y=0; j_off_y<N; j_off_y++){
                            char tG[4*N*N];
                            for(int  k=0; k<4*N*N; k++){
                                tG[k] = 0;
                            }
                            for(int  ky=0; ky<N; ky++){
                                for(int  kx=0; kx<N; kx++){
                                    if(G[i*N*N+ky*N+kx]){
                                        tG[(i_off_y+ky)*2*N+(i_off_x+kx)]++;
                                    }
                                    if(G[j*N*N+ky*N+kx]){
                                        tG[(j_off_y+ky)*2*N+(j_off_x+kx)]++;
                                    }
                                }
                            }
                            int x1;
                            int x2;
                            int y1;
                            int y2;
                            x1 = 2 * N - 1;
                            x2 = 0;
                            y1 = 2 * N - 1;
                            y2 = 0;
                            for(int  kx=0; kx<2*N; kx++){
                                for(int  ky=0; ky<2*N; ky++){
                                    if(tG[ky*2*N+kx]){
                                        if(x1 > kx){
                                            x1 = kx;
                                        }
                                        if(x2 < kx){
                                            x2 = kx;
                                        }
                                        if(y1 > ky){
                                            y1 = ky;
                                        }
                                        if(y2 < ky){
                                            y2 = ky;
                                        }
                                    }
                                }
                            }
                            if(x2 - x1 == Gx2 - Gx1 && y2 - y1 == Gy2 - Gy1){
                                bool flag = true;
                                for(int  kx=Gx1; kx<=Gx2; kx++){
                                    for(int  ky=Gy1; ky<=Gy2; ky++){
                                        if(G[ky*N+kx] != tG[(ky+y1-Gy1)*2*N+kx+x1-Gx1]){
                                            flag = false;
                                            break;
                                        }
                                    }
                                }
                                if(flag){
                                    printf("Got it: %d %d\n", i, j);
                                    FILE* Out = fopen("bcs.out", "w");
                                    fprintf(Out, "%d %d\n", i, j);
                                    fclose(Out);
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

