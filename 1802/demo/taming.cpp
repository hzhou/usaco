#include <vector>
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
    std::vector<struct entry> *plist_1 = new std::vector<struct entry>;
    std::vector<struct entry> *plist_2 = new std::vector<struct entry>;
    plist_1->push_back((struct entry) {0, 1, 0});
    for (int  i = 0; i<N; i++) {
        for(auto p : (*plist_1)){
            if (logs[i] != p.n_val) {
                plist_2->push_back((struct entry) {p.n_err + 1, p.n_breakout, p.n_val + 1});
                plist_2->push_back((struct entry) {p.n_err + 1, p.n_breakout + 1, 0});
            } else {
                plist_2->push_back((struct entry) {p.n_err, p.n_breakout, p.n_val + 1});
                plist_2->push_back((struct entry) {p.n_err, p.n_breakout + 1, 0});
            }
        }
        plist_1->clear();
        auto p = plist_1;
        plist_1 = plist_2;
        plist_2 = p;
    }
    int M[N];
    for (int  i = 0; i<N; i++) {
        M[i] = N;
    }
    for(auto p : (*plist_1)){
        if (p.n_val > 0) {
            i = p.n_breakout;
            if (M[i] > p.n_err) {
                M[i] = p.n_err;
            }
        }
    }
    for (int  i = 0; i<N; i++) {
        printf("%d\n", M[i]);
    }
    FILE* Out = fopen("taming.out", "w");
    for (int  i = 0; i<N; i++) {
        fprintf(Out, "%d\n", M[i]);
    }
    fclose(Out);
    return 0;
}
