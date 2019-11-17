#include <cstdio>
#include <climits>
#include <cstdio>
#include <algorithm>

int dist(int i, int j);

int *x_list;
int *y_list;
int DP[1001][1001][2];

int main(int argc, char** argv)
{
    int n;


    FILE* In = fopen("checklist.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int H;
    int G;
    fscanf(In, " %d %d" ,&H,&G);
    x_list = new int[H+G];
    y_list = new int[H+G];
    for (int  i = 0; i<H+G; i++) {
        fscanf(In, " %d %d" ,&x_list[i],&y_list[i]);
    }
    fclose(In);


    for (int  g = 1; g <= G; g++) {
        DP[0][g][0] = -1;
        DP[0][g][1] = -1;
    }
    DP[1][0][0] = 0;
    DP[1][0][1] = -1;
    for (int  h = 2; h <= H; h++) {
        DP[h][0][0] = DP[h-1][0][0] + dist(h - 2, h - 1);
        DP[h][0][1] = -1;
    }
    for (int  h = 1; h <= H; h++) {
        for (int  g = 1; g <= G; g++) {
            int t1;
            int t2;
            int t;
            t1 = DP[h-1][g][0] < 0 ? INT_MAX: DP[h-1][g][0] + dist(h - 2, h - 1);
            t2 = DP[h-1][g][1] < 0 ? INT_MAX: DP[h-1][g][1] + dist(H + g - 1, h - 1);
            t = std::min(t1, t2);
            DP[h][g][0]  = (t==INT_MAX? -1: t);

            t1 = DP[h][g - 1][0] < 0 ? INT_MAX: DP[h][g - 1][0] + dist(h - 1, H + g - 1);
            t2 = DP[h][g - 1][1] < 0 ? INT_MAX: DP[h][g - 1][1] + dist(H + g - 2, H + g - 1);
            t = std::min(t1, t2);
            DP[h][g][1]  = (t==INT_MAX? -1: t);
        }
    }
    n = DP[H][G][0];
    FILE* Out = fopen("checklist.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

int dist(int i, int j)
{
    int n_x;
    int n_y;

    n_x = x_list[i] - x_list[j];
    n_y = y_list[i] - y_list[j];
    return n_x * n_x + n_y * n_y;
}
