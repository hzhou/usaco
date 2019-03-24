#include <cstdio>
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
    int x1 = X[0];
    int x1_prev = X[1];
    int x1_idx = 0;
    int x2 = X[0];
    int x2_prev = X[1];
    int x2_idx = 0;
    int y1 = Y[0];
    int y1_prev = Y[1];
    int y1_idx = 0;
    int y2 = Y[0];
    int y2_prev = Y[1];
    int y2_idx = 0;
    for(int  i=1; i<N; i++){
        if(x1 > X[i]){
            x1_prev = x1;
            x1 = X[i];
            x1_idx = i;
        }
        else{
            if(x1 == X[i]){
                x1_idx = -1;
            }
            else if(x1_prev > X[i]){
                x1_prev = X[i];
            }
        }
        if(x2 < X[i]){
            x2_prev = x2;
            x2 = X[i];
            x2_idx = i;
        }
        else{
            if(x2 == X[i]){
                x2_idx = -1;
            }
            else if(x2_prev < X[i]){
                x2_prev = X[i];
            }
        }
        if(y1 > Y[i]){
            y1_prev = y1;
            y1 = Y[i];
            y1_idx = i;
        }
        else{
            if(y1 == Y[i]){
                y1_idx = -1;
            }
            else if(y1_prev > Y[i]){
                y1_prev = Y[i];
            }
        }
        if(y2 < Y[i]){
            y2_prev = y2;
            y2 = Y[i];
            y2_idx = i;
        }
        else{
            if(y2 == Y[i]){
                y2_idx = -1;
            }
            else if(y2_prev < Y[i]){
                y2_prev = Y[i];
            }
        }
    }
    int min_area = (x2-x1)*(y2-y1);
    std::cout<<"x1="<<x1<<", "<<"x2="<<x2<<", "<<"y1="<<y1<<", "<<"y2="<<y2<<'\n';
    std::cout<<"x1_idx="<<x1_idx<<", "<<"x2_idx="<<x2_idx<<", "<<"y1_idx="<<y1_idx<<", "<<"y2_idx="<<y2_idx<<'\n';
    std::cout<<"x1_prev="<<x1_prev<<", "<<"x2_prev="<<x2_prev<<", "<<"y1_prev="<<y1_prev<<", "<<"y2_prev="<<y2_prev<<'\n';
    std::cout<<"min_area="<<min_area<<'\n';
    if(x1_idx >= 0){
        int t_x1 = x1;
        if(x1_idx == x1_idx){
            t_x1 = x1_prev;
        }
        int t_x2 = x2;
        if(x2_idx == x1_idx){
            t_x2 = x2_prev;
        }
        int t_y1 = y1;
        if(y1_idx == x1_idx){
            t_y1 = y1_prev;
        }
        int t_y2 = y2;
        if(y2_idx == x1_idx){
            t_y2 = y2_prev;
        }
        std::cout<<"t_x2-t_x1="<<t_x2-t_x1<<", "<<"t_y2-t_y1="<<t_y2-t_y1<<'\n';
        if(min_area > (t_x2 - t_x1) * (t_y2 - t_y1)){
            min_area = (t_x2 - t_x1) * (t_y2 - t_y1);
            std::cout<<"min_area="<<min_area<<'\n';
        }
    }
    if(x2_idx >= 0){
        int t_x1 = x1;
        if(x1_idx == x2_idx){
            t_x1 = x1_prev;
        }
        int t_x2 = x2;
        if(x2_idx == x2_idx){
            t_x2 = x2_prev;
        }
        int t_y1 = y1;
        if(y1_idx == x2_idx){
            t_y1 = y1_prev;
        }
        int t_y2 = y2;
        if(y2_idx == x2_idx){
            t_y2 = y2_prev;
        }
        std::cout<<"t_x2-t_x1="<<t_x2-t_x1<<", "<<"t_y2-t_y1="<<t_y2-t_y1<<'\n';
        if(min_area > (t_x2 - t_x1) * (t_y2 - t_y1)){
            min_area = (t_x2 - t_x1) * (t_y2 - t_y1);
            std::cout<<"min_area="<<min_area<<'\n';
        }
    }
    if(y1_idx >= 0){
        int t_x1 = x1;
        if(x1_idx == y1_idx){
            t_x1 = x1_prev;
        }
        int t_x2 = x2;
        if(x2_idx == y1_idx){
            t_x2 = x2_prev;
        }
        int t_y1 = y1;
        if(y1_idx == y1_idx){
            t_y1 = y1_prev;
        }
        int t_y2 = y2;
        if(y2_idx == y1_idx){
            t_y2 = y2_prev;
        }
        std::cout<<"t_x2-t_x1="<<t_x2-t_x1<<", "<<"t_y2-t_y1="<<t_y2-t_y1<<'\n';
        if(min_area > (t_x2 - t_x1) * (t_y2 - t_y1)){
            min_area = (t_x2 - t_x1) * (t_y2 - t_y1);
            std::cout<<"min_area="<<min_area<<'\n';
        }
    }
    if(y2_idx >= 0){
        int t_x1 = x1;
        if(x1_idx == y2_idx){
            t_x1 = x1_prev;
        }
        int t_x2 = x2;
        if(x2_idx == y2_idx){
            t_x2 = x2_prev;
        }
        int t_y1 = y1;
        if(y1_idx == y2_idx){
            t_y1 = y1_prev;
        }
        int t_y2 = y2;
        if(y2_idx == y2_idx){
            t_y2 = y2_prev;
        }
        std::cout<<"t_x2-t_x1="<<t_x2-t_x1<<", "<<"t_y2-t_y1="<<t_y2-t_y1<<'\n';
        if(min_area > (t_x2 - t_x1) * (t_y2 - t_y1)){
            min_area = (t_x2 - t_x1) * (t_y2 - t_y1);
            std::cout<<"min_area="<<min_area<<'\n';
        }
    }
    FILE* Out = fopen("reduce.out", "w");
    fprintf(Out, "%d\n", min_area);
    fclose(Out);
    return 0;
}

