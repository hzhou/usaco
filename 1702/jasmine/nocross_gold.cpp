//Jasmine Zhang
//2 hours
//10 cases passed
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
int main () {
    FILE * In = fopen("nocross.in", "r");
    int N;
    fscanf(In, "%d", &N);

    int cows [N][2];
    for (int i = 0; i < N*2; i++) 
        fscanf(In, "%d", &cows[i%N][i/N]);
    /*
    cout << N << "\n";
    for (int i = 0; i < N; i++) {
        cout << cows[i][0] << " " << cows[i][1] << "\n";
    }
    */
    
    int DP [N+1][N+1]; //DP [i][j] = max num of disjoint connections with i on one side and j on the other
    for (int i = 0; i <= N; i++) {\
        DP[0][i] = 0;
        DP[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int a = 0;
            //originally didn't remember to subtract one from index, 
            //took a long time to figure out since it gave right answer on my computer
            //but not on the website for the sample case
            if (cows[i-1][0] - cows[j-1][1] <= 4 && cows[i-1][0] - cows[j-1][1] >= -4) {
                a = 1;
                //cout << a << " ";
            }
            DP[i][j] = max(DP[i-1][j], max(DP[i][j-1], DP[i-1][j-1]+a));
            //cout << i << "-" << j <<  "-" << DP[i][j] << " ";
        }
        //cout << "\n";
    }

    cout << DP[N][N];
    FILE * Out = fopen ("nocross.out", "w");
    fprintf(Out, "%d\n", DP[N][N]);

    return 0; 
}