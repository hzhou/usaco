#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct Rect {
	int x1;
	int x2;
	int y1;
	int y2;
};

bool is_PCL(int x1, int x2, int y1, int y2);
int find_region(int k, int x1, int x2, int y1, int y2);

int N;
char* grid;

int main(int argc, char** argv){
    FILE* In = fopen("where.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    grid = new char[N*N+1];
    for(int  i=0; i<N; i++){
        fscanf(In, "%s", grid + i * N);
    }
    fclose(In);
    std::vector<Rect> PCL_list;
    for(int  x1=0; x1<N; x1++){
        for(int  x2=x1+1; x2<N+1; x2++){
            for(int  y1=0; y1<N; y1++){
                for(int  y2=y1+1; y2<N+1; y2++){
                    if(is_PCL(x1, x2, y1, y2)){
                        PCL_list.push_back({x1, x2, y1, y2});
                    }
                }
            }
        }
    }
    int n_R=PCL_list.size();
    int count = 0;
    for(int  i=0; i<n_R; i++){
        bool is_maximal = true;
        for(int  j=0; j<n_R; j++){
            if(i == j){
                continue;
            }
            if(PCL_list[i].x1 >= PCL_list[j].x1 && PCL_list[i].x2 <= PCL_list[j].x2 && PCL_list[i].y1 >= PCL_list[j].y1 && PCL_list[i].y2 <= PCL_list[j].y2){
                is_maximal = false;
                break;
            }
        }
        if(is_maximal){
            count++;
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("where.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

bool is_PCL(int x1, int x2, int y1, int y2){
    int tn_a;
    int tn_b;
    char a = 0;
    char b = 0;
    int n_a = 0;
    int n_b = 0;
    int k_a = -1;
    int k_b = -1;
    for(int  i=y1; i<y2; i++){
        for(int  j=x1; j<x2; j++){
            char c = grid[i*N+j];
            if(a == 0){
                a = c;
                n_a++;
                k_a = i * N + j;
            }
            else if(c == a){
                n_a++;
            }
            else{
                if(b == 0){
                    b = c;
                    n_b++;
                    k_b = i * N + j;
                }
                else if(c == b){
                    n_b++;
                }
                else{
                    return false;
                }
            }
        }
    }
    if(n_b == 0){
        return false;
    }
    tn_a = find_region(k_a, x1, x2, y1, y2);
    tn_b = find_region(k_b, x1, x2, y1, y2);
    if((tn_a == n_a && tn_b < n_b) || (tn_b == n_b && tn_a < n_a)){
        return true;
    }
    return false;
}

int find_region(int k, int x1, int x2, int y1, int y2){
    int map[N*N] = {0};
    std::vector<int> stack;
    int count;
    int i;
    int i_y;
    int i_x;
    char c = grid[k];
    stack.push_back(k);
    count = 0;
    while(stack.size() > 0){
        i = stack.back();
        stack.pop_back();
        if(map[i] == 1){
            continue;
        }
        map[i] = 1;
        count++;
        i_y = i / N;
        i_x = i % N;
        if(i_x > x1 && grid[i-1] == c){
            stack.push_back(i - 1);
        }
        if(i_x + 1 < x2 && grid[i+1] == c){
            stack.push_back(i + 1);
        }
        if(i_y > y1 && grid[i-N] == c){
            stack.push_back(i - N);
        }
        if(i_y + 1 < y2 && grid[i+N] == c){
            stack.push_back(i + N);
        }
    }
    return count;
}

