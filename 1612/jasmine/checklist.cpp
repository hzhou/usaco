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
        fscanf(In, "%d %d", &hPos[N][0], &hPos[N][1]);
    for (int i = 0; i < M; i++) 
        fscanf(In, "%d %d", &gPos[N][0], &gPos[N][1]);

    int dp [N][M+1]; //dp[i][j] = min walking distance for i+1 Holsteins and j Guernseys
    std::pair <int,int> lastCoord [N][M+1]; //dp[i][j] = min walking distance for i+1 Holsteins and j Guernseys

    dp[0][0] = 0;
    for (int i = 1; i < N; i++) {
        dp[i][0] = dist(hPos[0][0], hPos[i][0], hPos[0][1], hPos[i][1]);
        lastCoord[i][0] = std::make_pair(hPos[i][0], hPos[i][1]);
    }
    for (int i = 1; i <= M; i++)  {
        dp[0][i] = dist(hPos[0][0], gPos[i-1][0], hPos[0][1], gPos[i-1][1]);
        lastCoord[0][i] = std::make_pair(gPos[i-1][0], gPos[i-1][1]);
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <=M; j++) {
            int v1 = dp[i-1][j] + dist(hPos[i][0], lastCoord[i-1][j].first, hPos[i][1], lastCoord[i-1][j].second);
            int v2 = dp[i][j-1] + dist(gPos[j-1][0], lastCoord[i][j-1].first, gPos[j-1][1], lastCoord[i][j-1].second);
            if (v1 < v2)
                dp[i][j] = v1;
            else
                dp[i][j] = v2;
        }
    }
    FILE * Out = fopen ("checklist.out", "w");
    fprintf(Out, "%d/n", dp[N-1][M]);

    return 0; 
}
int dist (int x1, int x2, int y1, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
