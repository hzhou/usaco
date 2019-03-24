#include <vector>
#include <cstdio>
#include <map>
#include <cstdio>
#include <algorithm>

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
    int x_list[H+G];
    int y_list[H+G];
    for (int  i = 0; i<H+G; i++) {
        fscanf(In, " %d %d" ,&x_list[i],&y_list[i]);
    }
    fclose(In);
    std::vector<std::pair<int,int> > Q;
    Q.push_back({0, 0});
    for (int  i = 1; i<H+G; i++) {
        std::map<int,int> M;
        for(auto q : Q){
            int j = q.first;
            int cost = q.second;
            if (j < H) {
                if (j + 1 < H) {
                    if (j + 1 != H - 1 || i == H + G - 1) {
                        int dx = x_list[j+1]-x_list[j];
                        int dy = y_list[j+1]-y_list[j];
                        int t = cost+dx*dx+dy*dy;
                        if (M.count(j + 1) == 0) {
                            M[j+1] = t;
                        } else if (M[j+1] > t) {
                            M[j+1] = t;
                        }
                    }
                }
                if (i - 1 - j < H + G) {
                    if (H + i - 1 - j != H - 1 || i == H + G - 1) {
                        int dx = x_list[H+i-1-j]-x_list[j];
                        int dy = y_list[H+i-1-j]-y_list[j];
                        int t = cost+dx*dx+dy*dy;
                        if (M.count(H + i - 1 - j) == 0) {
                            M[H+i-1-j] = t;
                        } else if (M[H+i-1-j] > t) {
                            M[H+i-1-j] = t;
                        }
                    }
                }
            } else {
                if (j + 1 < H + G) {
                    if (j + 1 != H - 1 || i == H + G - 1) {
                        int dx = x_list[j+1]-x_list[j];
                        int dy = y_list[j+1]-y_list[j];
                        int t = cost+dx*dx+dy*dy;
                        if (M.count(j + 1) == 0) {
                            M[j+1] = t;
                        } else if (M[j+1] > t) {
                            M[j+1] = t;
                        }
                    }
                }
                if (i - 1 - (j - H) < H) {
                    if (i - 1 - (j - H) != H - 1 || i == H + G - 1) {
                        int dx = x_list[i-1-(j-H)]-x_list[j];
                        int dy = y_list[i-1-(j-H)]-y_list[j];
                        int t = cost+dx*dx+dy*dy;
                        if (M.count(i - 1 - (j - H)) == 0) {
                            M[i-1-(j-H)] = t;
                        } else if (M[i-1-(j-H)] > t) {
                            M[i-1-(j-H)] = t;
                        }
                    }
                }
            }
        }
        Q.clear();
        for(auto it : M){
            Q.push_back(it);
        }
    }
    n = Q[0].second;
    FILE* Out = fopen("checklist.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}
