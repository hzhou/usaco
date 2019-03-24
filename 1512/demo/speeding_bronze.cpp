#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    int M;
    int i_seg;
    int i_car;
    FILE* In = fopen("speeding.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&M);
    std::cout<<"N="<<N<<", "<<"M="<<M<<'\n';
    int seg_l[N];
    int seg_v[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&seg_l[i],&seg_v[i]);
    }
    int car_l[M];
    int car_v[M];
    for(int  i=0; i<M; i++){
        fscanf(In, " %d %d" ,&car_l[i],&car_v[i]);
    }
    fclose(In);
    i_seg = 0;
    i_car = 0;
    int x_seg = 0;
    int x_car = 0;
    int max_over = 0;
    while(i_car < M){
        if(max_over < car_v[i_car] - seg_v[i_seg]){
            max_over = car_v[i_car] - seg_v[i_seg];
        }
        if(x_car + car_l[i_car] == x_seg + seg_l[i_seg]){
            x_car += car_l[i_car];
            i_car++;
            x_seg += seg_l[i_seg];
            i_seg++;
        }
        else if(x_car + car_l[i_car] < x_seg + seg_l[i_seg]){
            x_car += car_l[i_car];
            i_car++;
        }
        else{
            x_seg += seg_l[i_seg];
            i_seg++;
        }
    }
    std::cout<<"max_over="<<max_over<<'\n';
    FILE* Out = fopen("speeding.out", "w");
    fprintf(Out, "%d\n", max_over);
    fclose(Out);
    return 0;
}

