#include <vector>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("shortcut.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    int T;
    fscanf(In, " %d %d %d" ,&N,&M,&T);
    int c_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&c_list[i]);
    }
    int a_list[M];
    int b_list[M];
    int t_list[M];
    for (int  i = 0; i<M; i++) {
        fscanf(In, " %d %d %d" ,&a_list[i],&b_list[i],&t_list[i]);
        a_list[i]--;
        b_list[i]--;
    }
    fclose(In);
    std::vector<std::pair<int,int> > paths[N];
    for (int  i = 0; i<M; i++) {
        paths[a_list[i]].push_back({b_list[i], t_list[i]});
        paths[b_list[i]].push_back({a_list[i], t_list[i]});
    }
    int cost_list[N];
    for (int  i = 0; i<N; i++) {
        cost_list[i] = 0;
    }
    int dir_list[N];
    for (int  i = 0; i<N; i++) {
        dir_list[i] = 0;
    }
    std::set<std::pair<int,int>> stack;
    stack.insert({0, 0});
    while (stack.size() > 0) {
        auto it=stack.begin();
        int i;
        int cost;
        i = it->second;
        cost = it->first;
        stack.erase(it);
        for(auto it : paths[i]){
            if (it.first != 0) {
                if (cost_list[it.first] == 0 || cost + it.second < cost_list[it.first] || (cost + it.second == cost_list[it.first] && i < dir_list[it.first])) {
                    dir_list[it.first] = i;
                    cost_list[it.first] = cost + it.second;
                    stack.insert({cost + it.second, it.first});
                }
            }
        }
    }
    int tmp_list[N];
    for (int  i = 0; i<N; i++) {
        tmp_list[i] = 0;
    }
    for (int  i = 0; i<N; i++) {
        tmp_list[dir_list[i]]++;
    }
    int cows_list[N];
    for (int  i = 0; i<N; i++) {
        cows_list[i] = c_list[i];
    }
    std::vector<int> stack2;
    for (int  i = 0; i<N; i++) {
        if (tmp_list[i] == 0) {
            stack2.push_back(i);
        }
    }
    while (stack2.size() > 0) {
        int i = stack2.back();
        stack2.pop_back();
        cows_list[dir_list[i]] += cows_list[i];
        tmp_list[dir_list[i]]--;
        if (tmp_list[dir_list[i]] == 0) {
            stack2.push_back(dir_list[i]);
        }
    }
    long long ll_max = (long long)0;
    for (int  i = 0; i<N; i++) {
        long long ll_saving = (long long)cows_list[i]*(cost_list[i]-T);
        if (ll_max < ll_saving) {
            ll_max = ll_saving;
        }
    }
    std::cout<<"ll_max="<<ll_max<<'\n';
    FILE* Out = fopen("shortcut.out", "w");
    fprintf(Out, "%lld\n", ll_max);
    fclose(Out);
    return 0;
}
