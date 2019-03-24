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
    int tn_val;
    int tn_key;
    int n;
    int n_dir;
    int n_state;
    int k;
    double t_d1;
    double t_d2;

    FILE* In = fopen("cownav.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    grid = new char[N*N+1];
    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s", grid + i * N);
    }
    fclose(In);
    std::cout<<"N="<<N<<", "<<"grid="<<grid<<'\n';
    int n_ans = 0;
    std::deque<int> stack;
    std::unordered_set<int> cache;
    tn_val = 0 * 4 * 4 + 0 * 4 + 1;
    tn_val = tn_val * 400 * 400 + 0 * 400 + 0;
    tn_key = tn_val % (16 * 160000);
    if (cache.count(tn_key) == 0) {
        cache.insert(tn_key);
        stack.push_back(tn_val);
    }
    while (stack.size() > 0) {
        n = stack.front();
        stack.pop_front();
        n_dir = n / (400 * 400);
        n_state = n_dir / 16;
        n_dir %= 16;
        int count;
        int state;
        count = n_state / 4;
        state = n_state & 0x03;
        int d1;
        int d2;
        int k1;
        int k2;
        d1 = n_dir / 4;
        d2 = n_dir % 4;
        k1 = n / 400 % 400;
        k2 = n % 400;
        int t_k1;
        int t_k2;
        k = get_forward(d1, k1);
        if (grid[k] == 'E') {
            t_k1 = k;
        } else {
            t_k1 = k1;
        }
        k = get_forward(d2, k2);
        if (grid[k] == 'E') {
            t_k2 = k;
        } else {
            t_k2 = k2;
        }
        if (t_k1 == N * N - 1) {
            state |= 2;
        }
        if (t_k2 == N * N - 1) {
            state |= 1;
        }
        count++;
        if (state == 3) {
            n_ans = count;
            break;
        }
        tn_val = (count * 4 + state) * 4 * 4 + d1 * 4 + d2;
        tn_val = tn_val * 400 * 400 + t_k1 * 400 + t_k2;
        tn_key = tn_val % (16 * 160000);
        if (cache.count(tn_key) == 0) {
            cache.insert(tn_key);
            stack.push_back(tn_val);
        }
        t_d1 = (d1 - 1 + 4) % 4;
        t_d2 = (d2 - 1 + 4) % 4;
        tn_val = (n_state + 4) * 4 * 4 + t_d1 * 4 + t_d2;
        tn_val = tn_val * 400 * 400 + k1 * 400 + k2;
        tn_key = tn_val % (16 * 160000);
        if (cache.count(tn_key) == 0) {
            cache.insert(tn_key);
            stack.push_back(tn_val);
        }
        t_d1 = (d1 + 1) % 4;
        t_d2 = (d2 + 1) % 4;
        tn_val = (n_state + 4) * 4 * 4 + t_d1 * 4 + t_d2;
        tn_val = tn_val * 400 * 400 + k1 * 400 + k2;
        tn_key = tn_val % (16 * 160000);
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
    if (d == 0 && k / N < N - 1) {
        k += N;
    } else if (d == 1 && k % N < N - 1) {
        k++;
    } else if (d == 2 && k / N > 0) {
        k -= N;
    } else if (k % N > 0) {
        k--;
    }
    return k;
}
