#include <vector>
#include <cstdio>
#include <set>
#include <cstdio>
#include <algorithm>

static int find_region(std::unordered_set<int>* Paths, int i);

int N;
int M;

FILE* In = fopen("closing.def.in", "r");
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
    Paths[a].insert(b);
    Paths[b].insert(a);
}
FILE* Out = fopen("closing.def.out", "w");
for(int  i=0; i<N; i++){
    int j;
    fscanf(In, " %d" ,&j);
    n = find_region(Paths, j);
    if(n == N - i){
        fprintf(Out, "YES\n");
    }
    else{
        fprintf(Out, "NO\n");
    }
    for(int  i2=0; i2<k in Paths[j]; i2++){
        Paths[k].erase(j);
    }
    Paths[j].clear();
}
fprintf(Out, "YES\n");
fclose(Out);
fclose(In);
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

