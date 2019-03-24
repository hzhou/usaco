#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int i;
    int tn_ans;
    int j_tmp;
    int tn_i;
    int tn_j;
    int n_i;
    int n_j;
    int n;

    FILE* In = fopen("cowland.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int Q;
    fscanf(In, " %d %d" ,&N,&Q);
    int e_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&e_list[i]);
    }
    int A[N-1];
    int B[N-1];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    int type_list[Q];
    int i_list[Q];
    int v_list[Q];
    for (int  i = 0; i<Q; i++) {
        fscanf(In, " %d %d %d" ,&type_list[i],&i_list[i],&v_list[i]);
        if (type_list[i] == 1) {
            i_list[i]--;
        } else {
            i_list[i]--;
            v_list[i]--;
        }
    }
    fclose(In);
    std::vector<int> adj_list[N];
    for (int  i = 0; i<N-1; i++) {
        adj_list[A[i]].push_back(B[i]);
        adj_list[B[i]].push_back(A[i]);
    }
    int pointer_list[N];
    for (int  i = 0; i<N; i++) {
        pointer_list[i] = i;
    }
    int level_list[N];
    for (int  i = 0; i<N; i++) {
        level_list[i] = -1;
    }
    int cache[N];
    for (int  i = 0; i<N; i++) {
        cache[i] = 0;
    }
    std::vector<int> stack;
    stack.push_back(0);
    cache[0] = 1;
    level_list[0] = 0;
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();
        for(auto j : adj_list[i]){
            if (!cache[j]) {
                pointer_list[j] = i;
                level_list[j] = level_list[i] + 1;
                stack.push_back(j);
                cache[j] = 1;
            }
        }
    }
    std::vector<std::pair<int,int> > chains[10];
    int map_chain[N];
        for (int  i = 0; i<N; i++) {
            map_chain[i] = -1;
        }
    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        return level_list[a] > level_list[b];
    } );
    i = P[0];
    tn_ans = 0;
    while (pointer_list[i] != i) {
        tn_ans ^= e_list[i];
        chains[0].push_back({i, tn_ans});
        map_chain[i] = chains[0].size() - 1;
        i = pointer_list[i];
    }
    std::vector<int> ans_list;
    for (int  i = 0; i<Q; i++) {
        if (type_list[i] == 1) {
            if (map_chain[i_list[i]] >= 0) {
                j_tmp = map_chain[i_list[i]];
                int v_tmp = e_list[i_list[i]] ^ v_list[i];
                for (int  i2 = map_chain[i_list[i]]; i2<chains[0].size(); i2++) {
                    chains[0][i2].second ^= v_tmp;
                }
            }
            e_list[i_list[i]] = v_list[i];
        } else {
            tn_i = i_list[i];
            tn_j = v_list[i];
            n_i = level_list[tn_i];
            n_j = level_list[tn_j];
            tn_ans = 0;
            if (n_i > n_j) {
                n = n_i - n_j;
                tn_ans = 0;
                while (n > 0) {
                    if (map_chain[tn_i] < 0) {
                        tn_ans ^= e_list[tn_i];
                        tn_i = pointer_list[tn_i];
                        n--;
                        continue;
                    } else {
                        j_tmp = map_chain[tn_i];
                        if (j_tmp > 0) {
                            tn_ans ^= chains[0][j_tmp - 1].second;
                        }
                        tn_i = chains[0][j_tmp + n - 1].first;
                        tn_ans ^= chains[0][j_tmp + n - 1].second;
                        tn_i = pointer_list[tn_i];
                        break;
                    }
                }
            } else if (n_i < n_j) {
                n = n_j - n_i;
                tn_ans = 0;
                while (n > 0) {
                    if (map_chain[tn_j] < 0) {
                        tn_ans ^= e_list[tn_j];
                        tn_j = pointer_list[tn_j];
                        n--;
                        continue;
                    } else {
                        j_tmp = map_chain[tn_j];
                        if (j_tmp > 0) {
                            tn_ans ^= chains[0][j_tmp - 1].second;
                        }
                        tn_j = chains[0][j_tmp + n - 1].first;
                        tn_ans ^= chains[0][j_tmp + n - 1].second;
                        tn_j = pointer_list[tn_j];
                        break;
                    }
                }
            }
            while (1) {
                if (tn_i == tn_j) {
                    tn_ans ^= e_list[tn_i];
                    break;
                } else {
                    tn_ans ^= e_list[tn_i];
                    tn_ans ^= e_list[tn_j];
                    tn_i = pointer_list[tn_i];
                    tn_j = pointer_list[tn_j];
                }
            }
            ans_list.push_back(tn_ans);
        }
    }
    FILE* Out = fopen("cowland.out", "w");
    for(auto i : ans_list){
        fprintf(Out, "%d\n", i);
    }
    fclose(Out);
    return 0;
}
