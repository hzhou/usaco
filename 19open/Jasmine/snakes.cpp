//Jasmine Zhang
//1 case passed
//can't find bug
//2 hours
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main () {
    FILE * In = fopen("snakes.in", "r");
    int N, K;
    fscanf(In, "%d %d", &N, &K);
    
    int snakes [N];
    for (int i = 0; i < N; i++)
        fscanf(In, "%d", &snakes[i]);

    int dp [N][K+1];
    int lSwitch [N][K+1];
    int net [N][K+1];

    for (int i = 0; i < K+1; i++) {
        dp[0][i] = 0;
        lSwitch [0][i] = 0;
        net [0][i] = snakes[0];
    }

    for (int i = 1; i < N; i++) {
        int s = snakes[i];
        if (s > net[i-1][0]) {
            int w = dp[i-1][0] + ((s-net[i-1][0])*i);
            net[i][0] = s;
            dp[i][0] = w;
        }
        else {
            dp[i][0] = dp[i-1][0] + net[i-1][0] - s;
            net[i][0] = net[i-1][0];
        }
        cout << dp[i][0] << " ";
        for (int j = 1; j <= K; j++) {
            //switch size 
            int w1 = dp[i-1][j-1];
            int w2 = 0;
            if (s > net[i-1][j])
                w2 = dp[i-1][j] + ((s-net[i-1][j])*(i-lSwitch[i-1][j]));
            else 
                w2 = dp[i-1][j] + net[i-1][j] - s;
            //cout << w1 << "-" << w2 << " ";
            if (w1 > w2) {
                dp[i][j] = w2;
                lSwitch[i][j] = lSwitch[i-1][j];
                if (s <= net[i-1][j])
                    net[i][j] = net[i-1][j];
                else
                    net[i][j] = s;
            }
            else {
                dp[i][j] = w1;
                lSwitch[i][j] = i;
                net[i][j] = s;
            }
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    //cout << dp[N-1][K];

    FILE * Out = fopen ("snakes.out", "w");
    fprintf(Out, "%d\n", dp[N-1][K]);
    return 0;
}