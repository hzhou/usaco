#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdio>
#include <algorithm>

struct region {
	int cow_id;
	int size;
};

struct reg_pair {
	int i;
	int j;
};

void find_region(int idx);
int find_pair(int i, int j);

int N;
int* grid;
std::vector<struct region> region_list;
int n_regions;
std::unordered_map<int, int> M;
std::vector<int> pair_sizes;
std::vector<std::unordered_set<int> > region_neighbors;

int main(int argc, char** argv){
    int i_min;
    FILE* In = fopen("multimoo.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    grid = new int[N*N];
    for(int  i=0; i<N*N; i++){
        fscanf(In, " %d" ,&grid[i]);
    }
    fclose(In);
    i_min = 0;
    while(i_min < N * N){
        find_region(i_min);
        while(i_min < N * N && grid[i_min] < 0){
            i_min++;
        }
    }
    int max_size_1 = 0;
    for(int  i=0; i<region_list.size(); i++){
        if(max_size_1 < region_list[i].size){
            max_size_1 = region_list[i].size;
        }
    }
    printf("%d\n", max_size_1);
    n_regions = region_list.size();
    for(int  i=0; i<n_regions; i++){
        for(auto j : region_neighbors[i]){
            M[i*n_regions+j] = 1;
            M[j*n_regions+i] = 1;
        }
    }
    for(int  i=0; i<n_regions; i++){
        for(auto j : region_neighbors[i]){
            pair_sizes.push_back(find_pair(i, j));
        }
    }
    int max_size_2 = 0;
    for(auto size : pair_sizes){
        if(max_size_2 < size){
            max_size_2 = size;
        }
    }
    printf("%d\n", max_size_2);
    FILE* Out = fopen("multimoo.out", "w");
    fprintf(Out, "%d\n", max_size_1);
    fprintf(Out, "%d\n", max_size_2);
    fclose(Out);
    return 0;
}

void find_region(int idx){
    int i_reg;
    int i_cow;
    std::vector<int> stack;
    int n_size;
    int i;
    int n_L;
    int j;
    i_reg = region_list.size();
    i_cow = grid[idx];
    region_neighbors.resize(i_reg + 1);
    stack.push_back(idx);
    n_size = 0;
    while(stack.size() > 0){
        i = stack.back();
        stack.pop_back();
        if(grid[i] != i_cow){
            continue;
        }
        grid[i] = -(i_reg + 1);
        n_size++;
        int L[4];
        n_L = 0;
        int i_c = i % N;
        int i_r = i / N;
        if(i_c > 0){
            L[n_L++] = i - 1;
        }
        if(i_c + 1 < N){
            L[n_L++] = i + 1;
        }
        if(i_r > 0){
            L[n_L++] = i - N;
        }
        if(i_r + 1 < N){
            L[n_L++] = i + N;
        }
        for(int  _j=0; _j<n_L; _j++){
            j = L[_j];
            if(grid[j] == i_cow){
                stack.push_back(j);
            }
            else{
                if(grid[j] <= 0){
                    int j_reg = -grid[j]-1;
                    if(j_reg != i_reg){
                        region_neighbors[i_reg].insert(j_reg);
                        region_neighbors[j_reg].insert(i_reg);
                    }
                }
            }
        }
    }
    region_list.push_back({i_cow, n_size});
}

int find_pair(int i, int j){
    std::vector<struct reg_pair> stack;
    int n_size;
    std::unordered_map<int,int> cache;
    int i_cow = region_list[i].cow_id;
    int j_cow = region_list[j].cow_id;
    stack.push_back({i ,- 1});
    n_size = 0;
    while(stack.size() > 0){
        struct reg_pair P = stack.back();
        stack.pop_back();
        i = P.i;
        j = P.j;
        if(cache[i]){
            continue;
        }
        cache[i] = 1;
        n_size += region_list[i].size;
        for(auto j : region_neighbors[i]){
            if(M[i*n_regions+j]){
                if(region_list[j].cow_id == j_cow || region_list[j].cow_id == i_cow){
                    stack.push_back({j, i});
                    M[i*n_regions+j] = 0;
                    M[j*n_regions+i] = 0;
                }
            }
        }
    }
    return n_size;
}

