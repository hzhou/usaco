#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct Switch {
	int src;
	int dst;
};

int find_region(int* grid);
int find_switch(Switch * switches, int M, int k);

int N;
int M;
Switch* switches;

int main(int argc, char** argv){
    FILE* In = fopen("lightson.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&M);
    std::cout<<"N="<<N<<", "<<"M="<<M<<'\n';
    switches = new Switch[M];
    for(int  i=0; i<M; i++){
        int x;
        int y;
        int a;
        int b;
        fscanf(In, " %d %d %d %d" ,&x,&y,&a,&b);
        x--;
        y--;
        a--;
        b--;
        switches[i].src = x * N + y;
        switches[i].dst = a * N + b;
    }
    std::sort(switches, switches+M, [&](Switch a, Switch b){
        return a.src < b.src;
    } );
    fclose(In);
    int grid[N*N] = {0};
    grid[0] = 1;
    int total = 1;
    while(1){
        int cnt;
        cnt = find_region(grid);
        if(cnt == 0){
            break;
        }
        else{
            total += cnt;
        }
    }
    std::cout<<"total="<<total<<'\n';
    FILE* Out = fopen("lightson.out", "w");
    fprintf(Out, "%d\n", total);
    fclose(Out);
    return 0;
}

int find_region(int* grid){
    int cnt;
    int k;
    int i;
    int k2;
    int j;
    for(int  i=0; i<N*N; i++){
        if(grid[i] == -1){
            grid[i] = 1;
        }
    }
    cnt = 0;
    std::vector<int> stack;
    stack.push_back(0);
    while(stack.size() > 0){
        k = stack.back();
        stack.pop_back();
        if(grid[k] == 1){
            grid[k] = -1;
        }
        i = find_switch(switches, M, k);
        if(i >= 0){
            while(i<M && switches[i].src == k){
                k2 = switches[i].dst;
                if(grid[k2] == 0){
                    grid[k2] = 1;
                    cnt++;
                }
                i++;
            }
        }
        i = k / N;
        j = k % N;
        int L[4];
        int n_L = 0;
        if(i > 0){
            L[n_L++] = k - N;
        }
        if(i < N - 1){
            L[n_L++] = k + N;
        }
        if(j > 0){
            L[n_L++] = k - 1;
        }
        if(j < N - 1){
            L[n_L++] = k + 1;
        }
        for(int  i=0; i<n_L; i++){
            if(grid[L[i]] == 1){
                stack.push_back(L[i]);
            }
        }
    }
    return cnt;
}

int find_switch(Switch * switches, int M, int k){
    int i1;
    int i2;
    int i_middle;
    i1 = 0;
    i2 = M - 1;
    while(i1 < i2){
        if(switches[i1].src == k){
            return i1;
        }
        else if(switches[i2].src == k){
            while(switches[i2-1].src == k){
                i2--;
            }
            return i2;
        }
        i_middle = (i1 + i2) / 2;
        if(k == switches[i_middle].src){
            while(switches[i_middle-1].src == k){
                i_middle -= 1;
            }
            return i_middle;
        }
        else if(k < switches[i_middle].src){
            i2 = i_middle - 1;
        }
        else{
            i1 = i_middle + 1;
        }
    }
    return -1;
}

