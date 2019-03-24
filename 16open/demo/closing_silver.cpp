#include <vector>
#include <unordered_set>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int find_region(std::unordered_set<int>* Paths, int i);

int N;
int M;

int main(int argc, char** argv){
    int n;
    FILE* In = fopen("closing.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&M);
    std::unordered_set<int> Paths[N];
    for(int  i=0; i<M; i++){
        int a;
        int b;
        fscanf(In, " %d %d" ,&a,&b);
        a--;
        b--;
        Paths[a].insert(b);
        Paths[b].insert(a);
    }
    std::cout<<"N="<<N<<", "<<"M="<<M<<'\n';
    FILE* Out = fopen("closing.out", "w");
    for(int  i=0; i<N; i++){
        int j;
        fscanf(In, " %d" ,&j);
        j--;
        n = find_region(Paths, j);
        fprintf(stdout, "    :[erase] j=%d, n=%d\n", j, n);
        if(n == N - i){
            fprintf(Out, "YES\n");
        }
        else{
            fprintf(Out, "NO\n");
        }
        for(auto k : Paths[j]){
            Paths[k].erase(j);
        }
        Paths[j].clear();
    }
    fclose(Out);
    fclose(In);
    return 0;
}

int find_region(std::unordered_set<int>* Paths, int i){
    std::vector<int> stack;
    std::set<int> cache;
    stack.push_back(i);
    cache.insert(i);
    while(stack.size() > 0){
        i = stack.back();
        stack.pop_back();
        for(auto j : Paths[i]){
            if(cache.count(j) == 0){
                stack.push_back(j);
                cache.insert(j);
            }
        }
    }
    return cache.size();
}

