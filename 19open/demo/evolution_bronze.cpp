#include <vector>
#include <cstdio>
#include <map>
#include <cstdio>
#include <cassert>
#include <algorithm>

int get_attr(char *s);
bool is_proper(std::vector<int> & A, std::vector<int> & B);

std::map<std::string, int> attr_map;
int n_attr = 0;
int N;
int n;

int main(int argc, char** argv)
{
    int n_ret;


    FILE* In = fopen("evolution.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    n_ret = fscanf(In, " %d" ,&N);
    assert(n_ret > 0);
    std::vector<int> subpop[N];
    for (int  i = 0; i<N; i++) {
        n_ret = fscanf(In, " %d" ,&n);
        assert(n_ret > 0);
        char s[21];
        for (int  j = 0; j<n; j++) {
            fscanf(In, "%s", s);
            subpop[i].push_back(get_attr(s));
        }
    }
    fclose(In);

    for (int  i = 0; i<N; i++) {
        printf("%d [%d]: ", i, subpop[i].size());
        for(auto a : subpop[i]){
            printf("%d ", a);
        }
        puts("");
    }

    std::vector<int> attr_group[n_attr];
    for (int  i = 0; i<N; i++) {
        for(auto a : subpop[i]){
            attr_group[a].push_back(i);
        }
    }

    for (int  i = 0; i<n_attr; i++) {
        printf("attr %d: ", i);
        for(auto a : attr_group[i]){
            printf("%d ", a);
        }
        puts("");
    }

    bool proper = true;
    for (int  i = 0; i<n_attr; i++) {
        for (int  j = i+1; j<n_attr; j++) {
            bool t;
            if (attr_group[i].size() > attr_group[j].size()) {
                t = is_proper(attr_group[j], attr_group[i]);
            } else {
                t = is_proper(attr_group[i], attr_group[j]);
            }

            if (!t) {
                proper = false;
                goto ans;
            }
        }
    }

    ans:
        FILE* Out = fopen("evolution.out", "w");
        if (proper) {
            fprintf(Out, "yes\n");
        } else {
            fprintf(Out, "no\n");
        }
        fclose(Out);
    return 0;
}

int get_attr(char *s)
{
    std::string attr(s);
    if (attr_map.count(attr) == 0) {
        attr_map[attr] = n_attr++;
    }
    return attr_map[attr];
}

bool is_proper(std::vector<int> & A, std::vector<int> & B)
{
    int n_in;

    int in_B[N];
    for (int  i = 0; i<N; i++) {
        in_B[i] = 0;
    }
    for(auto b : B){
        in_B[b] = 1;
    }
    n_in = 0;
    for(auto a : A){
        if (in_B[a]) {
            n_in++;
        }
    }
    return n_in == A.size() || n_in == 0;
}
