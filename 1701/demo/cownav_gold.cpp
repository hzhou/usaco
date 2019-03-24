#include <unordered_set>
#include <cstdio>
#include <iostream>
#include <deque>
#include <cstdio>
#include <algorithm>

int get_forward(int d, int k);

int N;
char *grid;

int main(int argc, char** argv)
{
    int tn_key;
    int tn_val;
    int n;
    int n_count;
    double t_d1;
    int k;

    FILE* In = fopen("cownav.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    grid = new char[N*N];
    for (int  i = 0; i<N; i++) {
        char tmp[N+1];
        fscanf(In, "%s", tmp);
        for (int  j = 0; j<N; j++) {
            grid[(N-i-1)*N+j] = tmp[j];
        }
    }
    fclose(In);
    int N2 = N*N-1;
    int n_ans = 0;
    std::deque<int> stack;
    std::unordered_set<int> cache;
    tn_key = 0 * 160000 + 0 * 400 + 0;
    tn_val = 0 * 4 * 160000 + tn_key;
    if (cache.count(tn_key) == 0) {
        cache.insert(tn_key);
        stack.push_back(tn_val);
    }
    while (stack.size() > 0) {
        n = stack.front();
        stack.pop_front();
        n_count = n / (4 * 160000);
        int d1;
        int d2;
        int k1;
        int k2;
        d1 = n / 160000 % 4;
        d2 = (d1 + 1) % 4;
        k1 = n / 400 % 400;
        k2 = n % 400;
        n_count++;
        t_d1 = (d1 - 1 + 4) % 4;
        tn_key = t_d1 * 160000 + k1 * 400 + k2;
        tn_val = n_count * 4 * 160000 + tn_key;
        if (cache.count(tn_key) == 0) {
            cache.insert(tn_key);
            stack.push_back(tn_val);
        }
        t_d1 = (d1 + 1) % 4;
        tn_key = t_d1 * 160000 + k1 * 400 + k2;
        tn_val = n_count * 4 * 160000 + tn_key;
        if (cache.count(tn_key) == 0) {
            cache.insert(tn_key);
            stack.push_back(tn_val);
        }
        int t_k1;
        int t_k2;
        t_k1 = k1;
        t_k2 = k2;
        if (t_k1 < N2) {
            k = get_forward(d1, k1);
            if (grid[k] == 'E') {
                t_k1 = k;
            }
        }
        if (t_k2 < N2) {
            k = get_forward(d2, k2);
            if (grid[k] == 'E') {
                t_k2 = k;
            }
        }
        if (t_k1 == N2 && t_k2 == N2) {
            n_ans = n_count;
            break;
        }
        tn_key = d1 * 160000 + t_k1 * 400 + t_k2;
        tn_val = n_count * 4 * 160000 + tn_key;
        if (cache.count(tn_key) == 0) {
            cache.insert(tn_key);
            stack.push_back(tn_val);
        }
    }
    std::cout<<"n_ans="<<n_ans<<'\n';
    FILE* Out = fopen("cownav.out", "w");
    fprintf(Out, "%d\n", n_ans);
    fclose(Out);
    return 0;
}

int get_forward(int d, int k)
{
    int i;
    int j;

    i = k / N;
    j = k % N;
    if (d == 0 && i < N - 1) {
        k += N;
    } else if (d == 1 && j < N - 1) {
        k++;
    } else if (d == 2 && i > 0) {
        k -= N;
    } else if (d == 3 && j > 0) {
        k--;
    }
    return k;
}
