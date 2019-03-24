#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <algorithm>

void find_region(int idx);

int N;
int K;
int R;
int* grid;
std::vector<int> region_list;

int main(int argc, char** argv){
    int k;
    int i_min;
    int n_regions;
    int n;
    FILE* In = fopen("countcross.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&N,&K,&R);
    std::cout<<"N="<<N<<", "<<"K="<<K<<", "<<"R="<<R<<'\n';
    grid = new int[N*N];
    for(int  i=0; i<N*N; i++){
        grid[i] = 0;
    }
    for(int  i=0; i<N; i++){
        grid[i] |= 1;
        grid[(N-1)*N+i] |= 4;
        grid[i*N] |= 8;
        grid[i*N+N-1] |= 2;
    }
    for(int  i=0; i<R; i++){
        int a;
        int b;
        int c;
        int d;
        fscanf(In, " %d %d %d %d" ,&a,&b,&c,&d);
        k = (a - 1) * N + (b - 1);
        if(a == c){
            if(b + 1 == d){
                grid[k] |= 2;
                grid[k+1] |= 8;
            }
            else if(b - 1 == d){
                grid[k] |= 8;
                grid[k-1] |= 2;
            }
        }
        else if(b == d){
            if(a + 1 == c){
                grid[k] |= 4;
                grid[k+N] |= 1;
            }
            else if(a - 1 == c){
                grid[k] |= 1;
                grid[k-N] |= 4;
            }
        }
    }
    for(int  i=0; i<K; i++){
        int a;
        int b;
        fscanf(In, " %d %d" ,&a,&b);
        k = (a - 1) * N + (b - 1);
        grid[k] |= 0x10;
    }
    fclose(In);
    i_min = 0;
    while(i_min < N * N){
        find_region(i_min);
        while(i_min < N * N && grid[i_min] < 0){
            i_min++;
        }
    }
    n_regions = region_list.size();
    std::cout<<"n_regions="<<n_regions<<'\n';
    n = 0;
    if(n_regions > 1){
        for(int  i=0; i<n_regions; i++){
            for(int  j=i+1; j<n_regions; j++){
                n += region_list[i] * region_list[j];
            }
        }
    }
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("countcross.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

void find_region(int idx){
    int i_reg;
    std::vector<int> stack;
    int i;
    i_reg = region_list.size();
    stack.push_back(idx);
    int count = 0;
    while(stack.size() > 0){
        i = stack.back();
        stack.pop_back();
        if(grid[i] < 0){
            continue;
        }
        int m = grid[i];
        grid[i] = -1;
        if(m & 0x10){
            count++;
        }
        if((m & 1) == 0){
            stack.push_back(i - N);
        }
        if((m & 4) == 0){
            stack.push_back(i + N);
        }
        if((m & 8) == 0){
            stack.push_back(i - 1);
        }
        if((m & 2) == 0){
            stack.push_back(i + 1);
        }
    }
    region_list.push_back(count);
}

