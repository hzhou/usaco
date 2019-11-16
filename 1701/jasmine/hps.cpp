//Jasmine Zhang
//1.5 hours
//10/10 cases passed
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>


using namespace std;
int main () {
    FILE * In = fopen("hps.in", "r");
    int N, K;
    fscanf(In, "%d %d", &N, &K);

    //0 = hoof
    //1 = paper
    //2 = scissors 
    int farmerMoves [N];
    for (int i = 0; i < N; i++) { 
        char c;
        fscanf(In, " %c\n", &c);
        if (c == 'H')
            farmerMoves[i] = 0;
        else if (c == 'P')
            farmerMoves[i] = 1;
        else
            farmerMoves[i] = 2;
    }

    //use equal as beats since only tracking wins
    int dp [N+1][K+1][3]; //n moves, k switches, i states (h/p/s)
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;
    for (int n = 1; n <= N; n++) {
        for (int i = 0; i < 3; i++) {
            int a = 0;
            if (i == farmerMoves[n-1])
                a = 1;
            //cout << a << "-";
            dp[n][0][i] = dp[n-1][0][i] + a;
            //cout << dp[n][0][i] << " ";
        }
        //cout << "\n";
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < 3; i++) {
            dp[0][k][i] = 0;
            //cout << dp[0][k][i] << " ";
        }
        //cout << "\n";
    }

    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= K; k++) {
             for (int i = 0; i < 3; i++) {
                  int a = 0;
                if (i == farmerMoves[n-1])
                    a = 1;
                int change = max(dp[n-1][k-1][(i+1)%3]+a,dp[n-1][k-1][(i+2)%3]+a);
                //cout << change << " ";
                int same = dp[n-1][k][i]+a;
                //cout << dp[n-1][k][i] << "-" << n-1 << "-" << k << " ";
                dp[n][k][i] = max(change, same);
             }
             //cout << "\n";
        }
    }

    int m;
    m = max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2]));
    cout << m;

    FILE * Out = fopen("hps.out", "w");
    fprintf(Out, "%d\n", m);

    return 0; 
}