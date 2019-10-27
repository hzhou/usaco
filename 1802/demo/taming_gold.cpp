#include <vector>
#include <unordered_map>
#include <cstdio>
#include <cstdio>
#include <algorithm>

struct entry {
    int n_err;
    int n_breakout;
    int n_val;
};


int main(int argc, char** argv)
{
    int k;
    int n_breakout;
    int n_val;
    int n_err;
    int i;


    FILE* In = fopen("taming.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int logs[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&logs[i]);
    }
    fclose(In);
    printf("logs[%d]: ", N);
    for (int  _i = 0; _i<N; _i++) {
        printf("%d ", logs[_i]);
    }
    puts("");

    std::vector<struct entry> *plist = new std::vector<struct entry>;
    plist->push_back((struct entry) {0, 1, 0});

    for (int  i = 0; i<N; i++) {
        std::unordered_map<int, int> M;
        for(auto p : (*plist)){
            if (logs[i] != p.n_val) {
                k = (p.n_breakout) * (N + 1) + p.n_val + 1;
                if (M.count(k) == 0) {
                    M[k] = p.n_err + 1;
                } else {
                    if (M[k] > p.n_err + 1) {
                        M[k] = p.n_err + 1;
                    }
                }
                k = (p.n_breakout + 1) * (N + 1) + 0;
                if (M.count(k) == 0) {
                    M[k] = p.n_err + 1;
                } else {
                    if (M[k] > p.n_err + 1) {
                        M[k] = p.n_err + 1;
                    }
                }
            } else {
                k = (p.n_breakout) * (N + 1) + p.n_val + 1;
                if (M.count(k) == 0) {
                    M[k] = p.n_err;
                } else {
                    if (M[k] > p.n_err) {
                        M[k] = p.n_err;
                    }
                }
                k = (p.n_breakout + 1) * (N + 1) + 0;
                if (M.count(k) == 0) {
                    M[k] = p.n_err;
                } else {
                    if (M[k] > p.n_err) {
                        M[k] = p.n_err;
                    }
                }
            }
        }

        plist->clear();
        for (auto it=M.begin(); it!=M.end(); it++) {
            n_breakout = it->first / (N + 1);
            n_val = it->first % (N + 1);
            n_err = it->second;
            plist->push_back((struct entry) {n_err, n_breakout, n_val});
        }
    }

    int M[N];
    for (int  i = 0; i<N; i++) {
        M[i] = N;
    }

    for(auto p : (*plist)){
        if (p.n_val > 0) {
            i = p.n_breakout - 1;
            if (M[i] > p.n_err) {
                M[i] = p.n_err;
            }
        }
    }

    FILE* Out = fopen("taming.out", "w");
    for (int  i = 0; i<N; i++) {
        fprintf(Out, "%d\n", M[i]);
    }
    fclose(Out);

    return 0;
}
