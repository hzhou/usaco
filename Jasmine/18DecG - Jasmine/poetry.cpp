#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

long long MOD = 1000000007;
//???????????????????????
//(ab) mod p = ( (a mod p) (b mod p) ) mod p 
//fig out mod power
long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + MOD) % MOD;
   long long ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if(power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}

int main () {
    FILE * In = fopen("poetry.in", "r");
    int N, M, K;
    fscanf(In, "%d %d %d", &N, &M, &K);
    
    long long words [2][K];
    long long lengths[K];
    fill_n(lengths, K, 0);
    long long dp [K+1];
    fill_n(dp, K+1, 0);
    
     
    for (int i = 0; i < N; i++) { 
        fscanf(In, "%lld %lld", &words[0][i], &words[1][i]);
        lengths[words[0][i]-1] += 1;
    }
    
    //issues here :(
    dp[0] = 1;
    for (int i = 0; i <= K; i++) {
        dp[i] = dp[0]*lengths[i-1];
        
        for (int j = 1; j <= K/2 && j < i; j++) {
            //cout << dp[i] << " ";
            dp[i] += (dp[j]*dp[i-j]) % MOD;
        }
        
        /* 
        for (int j = 0; j < N; j++) {
            //cout << words[0][j] << " " << i << "\n";
            if(words[0][j] + i > K) 
                continue;
            //knapsack????
            dp[words[0][j] + i] = (dp[words[0][j] + i] + dp[i] + MOD) % MOD; 
        }
        */
        //dp[i] %= MOD;
        
        
    }
    //cout << words[0][2];
    //for (int i = 0; i <= K; i++) 
        //cout << dp[i] << " ";
    //cout << "\n";
    map <long long, long long> rhymes;
    //cout << dp[K-50];
    for (int i = 0; i < N; i++) {
        rhymes[words[1][i]] += dp[K-words[0][i]];
        //rhymes[words[1][i]] = (rhymes[words[1][i]]+MOD) % MOD;
        //cout << words[1][i] << " " << K - words[0][i] << " " << rhymes[words[1][i]] << "\n";
    }
    
    map <int, int> lines; 
    for (int i = 0; i < M; i++) {
        char c; 
        //put space before
        fscanf(In, " %c", &c);
        lines[c]++;
        //cout << c << " " << lines[c] << "\n";
    }
    long long tot = 1;
    for (pair <char, int> l: lines) {
        int pow = l.second;
        int t = 0;
        for (pair <long long, long long> r : rhymes) {
            int base = r.second;
            //cout << base << " " << pow << "\n";
            if (base == 0)
                continue;
            t += exp(base, pow) + MOD;
            t %= MOD;
        }
        tot *= t;
        tot %= MOD;
    }
    
    FILE * Out = fopen("poetry.out", "w");
    fprintf(Out, "%lld\n", tot);

    return 0;
}