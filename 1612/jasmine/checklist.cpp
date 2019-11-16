//Jasmine Zhang
//buggy code
//2 hours 
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>


int dist (int x1, int x2, int y1, int y2);
int main () {
    FILE * In = fopen("checklist.in", "r");
    int N, M;
    fscanf(In, "%d %d", &N, &M);

    int hPos [N][2];
    int gPos [M][2];

    for (int i = 0; i < N; i++) 
        fscanf(In, "%d %d", &hPos[i][0], &hPos[i][1]);
    for (int i = 0; i < M; i++) 
        fscanf(In, "%d %d", &gPos[i][0], &gPos[i][1]);

    int dp [N-1][M+1]; //dp[i][j] = min walking distance for i+1 Holsteins and j Guernseys
    std::pair <int,int> lastCoord [N][M+1]; 
    lastCoord[0][0] = std::make_pair(hPos[0][0], hPos[0][1]);
    
    dp[0][0] = 0;
    for (int i = 1; i < N-1; i++) {
        dp[i][0] = dist(hPos[i][0], lastCoord[i-1][0].first, hPos[i][1], lastCoord[i-1][0].second) + dp[i-1][0];
        lastCoord[i][0] = std::make_pair(hPos[i][0], hPos[i][1]);
        //std::cout << dp[i][0] << "\n";
    }
    for (int i = 1; i <= M; i++)  {
        dp[0][i] = dist(gPos[i-1][0], lastCoord[0][i-1].first, gPos[i-1][1], lastCoord[0][i-1].second) + dp[0][i-1];
        lastCoord[0][i] = std::make_pair(gPos[i-1][0], gPos[i-1][1]);
        //std::cout << dp[0][i] << "\n";
    }
    
    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j <=M; j++) {
            int v1 = dp[i-1][j] + dist(hPos[i][0], lastCoord[i-1][j].first, hPos[i][1], lastCoord[i-1][j].second);
            int v2 = dp[i][j-1] + dist(gPos[j-1][0], lastCoord[i][j-1].first, gPos[j-1][1], lastCoord[i][j-1].second);
            if (i == N-2 && j == M) {
                //std::cout << v1 << " " << v2 << "\n";
                v1 += dist(hPos[i][0], hPos[N-1][0], hPos[i][1], hPos[N-1][1]);
                v2 += dist(gPos[j-1][0], hPos[N-1][0], gPos[j-1][1], hPos[N-1][1]);
                //std::cout <<  hPos[N-1][0] << " " << hPos[N-1][0]) << "\n";
                //std::cout << v1 << " " << v2 << "\n";
            }
            if (v1 < v2) {
                dp[i][j] = v1;
                lastCoord[i][j] = std::make_pair(hPos[i][0], hPos[i][1]);
            }
            else {
                dp[i][j] = v2;
                lastCoord[i][j] = std::make_pair(gPos[j-1][0], gPos[j-1][1]);
            }
        }
    }
    //std::cout << dp[N-2][M] << "\n";
    //std::cout << lastCoord[N-2][M].first << " " << lastCoord[N-2][M].second << "\n";

    //std::cout << dp[N-1][M-1] << "\n";
    //std::cout << lastCoord[N-1][M-1].first << " " << lastCoord[N-1][M-1].second << "\n";
    FILE * Out = fopen ("checklist.out", "w");
    fprintf(Out, "%d\n", dp[N-2][M]);

    return 0; 
}
int dist (int x1, int x2, int y1, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
