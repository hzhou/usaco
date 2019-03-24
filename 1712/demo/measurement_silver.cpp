#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

// learn: sort, vector, map (hashmap)

struct log_entry {
	int day;
	int cow;
	int change;
};

bool log_cmp(struct log_entry a, struct log_entry b);

using namespace std;
int main(int argc, char** argv){
    FILE* In = fopen("measurement.in", "r");
    int N;
    int G;
    fscanf(In, "%d %d", &N, &G);
    vector<struct log_entry> logs;
    for(int  i=0; i<N; i++){
        int day;
        int cow;
        int change;
        fscanf(In, "%d %d %d", &day, &cow, &change);
        logs.push_back({day, cow, change});
    }
    fclose(In);

    sort(logs.begin(), logs.end(), log_cmp);

    int count = 0;
    unordered_map<int, int> M;
    int n_max = G;
    int n_dup = 0;
    for(int  i=0; i<N; i++){
        bool need_update = false;
        bool was_max = false;
        // First, update milk output value t
        int t = G;
        // auto is a c++11 feature, type induction
        auto it = M.find(logs[i].cow);
        if(it == M.end()){
            if(n_max == G){
                was_max = true;
            }
            t = G + logs[i].change;
            M[logs[i].cow] = t;
        }
        else{
            if(it->second == n_max){
                was_max = true;
            }
            t = it->second + logs[i].change;
            it->second = t;
        }

        // update max and decide update
        if(n_max < t){
            if(!was_max || n_dup != 1){
                need_update = 1;
            }
            n_max = t;
            n_dup = 1;
        }
        else if(n_max == t){
            need_update = 1;
            n_dup++;
        }
        else if(was_max){
            if(n_dup == 1){
                n_max = G;
                n_dup = 0;
                for(auto it : M){
                    if(n_max < it.second){
                        n_max = it.second;
                        n_dup = 1;
                    }
                    else if(n_max == it.second){
                        n_dup++;
                    }
                }
                if(n_max != t || n_dup > 1){
                    need_update = 1;
                }
            }
            else{
                n_dup--;
                need_update = 1;
            }
        }
        // update count
        if(need_update){
            count++;
        }
    }

    FILE* Out = fopen("measurement.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

bool log_cmp(struct log_entry a, struct log_entry b){
    return a.day < b.day;
}

