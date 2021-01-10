#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>

int modpow(int t, int n);

int N;
int M;
int K;

int main(int argc, char** argv)
{
    int n_ret;
    int n_sub_count;
    int n;
    int count;
    int i_m;
    int k;

    FILE* In = fopen("poetry.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    n_ret = fscanf(In, " %d %d %d" ,&N,&M,&K);
    assert(n_ret > 0);
    int s_list[N];
    int c_list[N];
    for (int  i = 0; i<N; i++) {
        n_ret = fscanf(In, " %d %d" ,&s_list[i],&c_list[i]);
        assert(n_ret > 0);
        c_list[i] -= 1;
    }
    char line_rhymes[M+1];
    for (int  i = 0; i<M; i++) {
        n_ret = fscanf(In, "%s", line_rhymes + i);
        assert(n_ret > 0);
    }
    fclose(In);

    int r_counts[26];
    for (int  i = 0; i<26; i++) {
        r_counts[i] = 0;
    }
    for (int  i = 0; i<M; i++) {
        r_counts[line_rhymes[i]-'A']++;
    }

    int n_count = 0;
    std::unordered_map<int,int> map_syllables;
    for (int  i = 0; i<N; i++) {
        if (map_syllables.count(s_list[i]) == 0) {
            map_syllables[s_list[i]] = 1;
        } else {
            map_syllables[s_list[i]]++;
        }
    }
    std::unordered_map<int,int> map_line_rhymes;
    for (int  i = 0; i<M; i++) {
        if (map_line_rhymes.count(line_rhymes[i]) == 0) {
            map_line_rhymes[line_rhymes[i]] = 1;
        } else {
            map_line_rhymes[line_rhymes[i]]++;
        }
    }
    std::unordered_map<int,int> map_class_ids;
    int n_c = 0;
    for (int  j = 0; j<N; j++) {
        if (map_class_ids.count(c_list[j]) == 0) {
            map_class_ids[c_list[j]] = n_c;
            n_c++;
        }
        c_list[j] = map_class_ids[c_list[j]];
    }
    int n_m = 0;
    for(auto t : map_line_rhymes){
        if (n_m < t.second) {
            n_m = t.second;
        }
    }
    int pn_all[K];
    for (int  i = 0; i<K; i++) {
        pn_all[i] = 0;
    }
    pn_all[0] = 1;

    for (int  k = 1; k<K; k++) {
        n_sub_count = 0;
        for(auto t : map_syllables){
            n = t.first;
            count = t.second;
            if (k - n >= 0 && pn_all[k-n] > 0) {
                count = (int) (((long long) count * pn_all[k-n]) % 1000000007);
                n_sub_count = (n_sub_count + count) % 1000000007;
            }
        }
        pn_all[k] = n_sub_count;
    }
    int pn_classes[n_c];
    for (int  i = 0; i<n_c; i++) {
        pn_classes[i] = 0;
    }

    for (int  j = 0; j<N; j++) {
        if (K - s_list[j] >= 0) {
            pn_classes[c_list[j]] = (pn_classes[c_list[j]] + pn_all[K-s_list[j]]) % 1000000007;
        }
    }
    std::unordered_set<int> set_counts;
    for(auto t : map_line_rhymes){
        set_counts.insert(t.second);
    }
    int pn_count_all[n_m];
    if (set_counts.size() < 10) {
        printf("only %d counts: do get_count_all_direct ...\n", (int) set_counts.size());
        for (int  i = 0; i<n_m; i++) {
            pn_count_all[i] = 0;
        }
        for(auto i : set_counts){
            i_m = i - 1;
            for (int  j = 0; j<n_c; j++) {
                pn_count_all[i_m] = (pn_count_all[i_m] + modpow(pn_classes[j], i)) % 1000000007;
            }
        }
    } else {
        std::cout<<"n_c="<<n_c<<", "<<"n_m="<<n_m<<'\n';
        int *pn_class_all;
        pn_class_all = new int[n_c*n_m];
        if (1) {
            for (int  j = 0; j<n_c; j++) {
                pn_class_all[j] = pn_classes[j];
            }
        }
        k = n_c;
        for (int  i = 1; i<n_m; i++) {
            for (int  j = 0; j<n_c; j++) {
                pn_class_all[k] = pn_class_all[k-n_c];
                pn_class_all[k] = (int) (((long long) pn_class_all[k] * pn_classes[j]) % 1000000007);
                k++;
            }
        }

        for (int  i = 0; i<n_m; i++) {
            pn_count_all[i] = 0;
        }
        k = 0;
        for (int  i = 0; i<n_m; i++) {
            for (int  j = 0; j<n_c; j++) {
                pn_count_all[i] = (pn_count_all[i] + pn_class_all[k]) % 1000000007;
                k++;
            }
        }
    }
    n_count = 1;
    for(auto t : map_line_rhymes){
        count = t.second;
        n_count = (int) (((long long) n_count * pn_count_all[count-1]) % 1000000007);
    }
    std::cout<<"n_count="<<n_count<<'\n';
    FILE* Out = fopen("poetry.out", "w");
    fprintf(Out, "%d\n", n_count);
    fclose(Out);
    return 0;
}

int modpow(int t, int n)
{
    int n_half;
    int n_tmp;

    if (n == 1) {
        return t;
    }
    n_half = n / 2;
    n_tmp = modpow(t, n_half);
    n_tmp = (int) (((long long) n_tmp * n_tmp) % 1000000007);
    if (n - n_half * 2 == 1) {
        n_tmp = (int) (((long long) n_tmp * t) % 1000000007);
    }
    return n_tmp;
}
