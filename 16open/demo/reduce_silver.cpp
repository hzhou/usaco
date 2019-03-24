#include <unordered_set>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    FILE* In = fopen("reduce.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int X[N];
    int Y[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&X[i],&Y[i]);
    }
    fclose(In);
    int x1[4] = {-1,-1,-1,-1};
    int x1_idx[4] = {-1,-1,-1,-1};
    int x2[4] = {-1,-1,-1,-1};
    int x2_idx[4] = {-1,-1,-1,-1};
    int y1[4] = {-1,-1,-1,-1};
    int y1_idx[4] = {-1,-1,-1,-1};
    int y2[4] = {-1,-1,-1,-1};
    int y2_idx[4] = {-1,-1,-1,-1};
    for(int  i=0; i<N; i++){
        for(int  j=0; j<4; j++){
            if(x1[j] > X[i] || x1[j] == -1){
                for(int  k=3; k>=j+1; k--){
                    x1[k] = x1[k-1];
                    x1_idx[k] = x1_idx[k-1];
                }
                x1[j] = X[i];
                x1_idx[j] = i;
                break;
            }
        }
        for(int  j=0; j<4; j++){
            if(x2[j] < X[i] || x2[j] == -1){
                for(int  k=3; k>=j+1; k--){
                    x2[k] = x2[k-1];
                    x2_idx[k] = x2_idx[k-1];
                }
                x2[j] = X[i];
                x2_idx[j] = i;
                break;
            }
        }
        for(int  j=0; j<4; j++){
            if(y1[j] > Y[i] || y1[j] == -1){
                for(int  k=3; k>=j+1; k--){
                    y1[k] = y1[k-1];
                    y1_idx[k] = y1_idx[k-1];
                }
                y1[j] = Y[i];
                y1_idx[j] = i;
                break;
            }
        }
        for(int  j=0; j<4; j++){
            if(y2[j] < Y[i] || y2[j] == -1){
                for(int  k=3; k>=j+1; k--){
                    y2[k] = y2[k-1];
                    y2_idx[k] = y2_idx[k-1];
                }
                y2[j] = Y[i];
                y2_idx[j] = i;
                break;
            }
        }
    }
    std::cout<<"x1[0]="<<x1[0]<<", "<<"x1[1]="<<x1[1]<<", "<<"x1[2]="<<x1[2]<<", "<<"x1[3]="<<x1[3]<<'\n';
    std::cout<<"x2[0]="<<x2[0]<<", "<<"x2[1]="<<x2[1]<<", "<<"x2[2]="<<x2[2]<<", "<<"x2[3]="<<x2[3]<<'\n';
    std::cout<<"y1[0]="<<y1[0]<<", "<<"y1[1]="<<y1[1]<<", "<<"y1[2]="<<y1[2]<<", "<<"y1[3]="<<y1[3]<<'\n';
    std::cout<<"y2[0]="<<y2[0]<<", "<<"y2[1]="<<y2[1]<<", "<<"y2[2]="<<y2[2]<<", "<<"y2[3]="<<y2[3]<<'\n';
    int min_area = (x2[0]-x1[0])*(y2[0]-y1[0]);
    for(int  a=0; a<4; a++){
        for(int  b=0; b<4; b++){
            for(int  c=0; c<4; c++){
                for(int  d=0; d<4; d++){
                    std::unordered_set<int> S;
                    for(int  i=0; i<a; i++){
                        S.insert(x1_idx[i]);
                    }
                    for(int  i=0; i<b; i++){
                        S.insert(x2_idx[i]);
                    }
                    for(int  i=0; i<c; i++){
                        S.insert(y1_idx[i]);
                    }
                    for(int  i=0; i<d; i++){
                        S.insert(y2_idx[i]);
                    }
                    if(S.size() != 3){
                        continue;
                    }
                    int t_x1;
                    for(int  i=a; i<4; i++){
                        if(S.count(x1_idx[i]) == 0){
                            t_x1 = x1[i];
                            break;
                        }
                    }
                    int t_x2;
                    for(int  i=b; i<4; i++){
                        if(S.count(x2_idx[i]) == 0){
                            t_x2 = x2[i];
                            break;
                        }
                    }
                    int t_y1;
                    for(int  i=c; i<4; i++){
                        if(S.count(y1_idx[i]) == 0){
                            t_y1 = y1[i];
                            break;
                        }
                    }
                    int t_y2;
                    for(int  i=d; i<4; i++){
                        if(S.count(y2_idx[i]) == 0){
                            t_y2 = y2[i];
                            break;
                        }
                    }
                    if(min_area > (t_x2 - t_x1) * (t_y2 - t_y1)){
                        min_area = (t_x2 - t_x1) * (t_y2 - t_y1);
                        std::cout<<"min_area="<<min_area<<'\n';
                    }
                }
            }
        }
    }
    FILE* Out = fopen("reduce.out", "w");
    fprintf(Out, "%d\n", min_area);
    fclose(Out);
    return 0;
}

