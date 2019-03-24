#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

struct PCL {
    int x1;
    int y1;
    int x2;
    int y2;
};

char *grid;
int *flags;
int flagIndex;
int N;

int isPCL(int x1, int y1, int x2, int y2);
int main() {
    FILE *fileIn = fopen("where.in", "r");
    FILE *fileOut = fopen("where.out", "w");

    fscanf(fileIn, "%d", &N);

    grid = new char[N*N+1];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%s", grid + i*N);
    }

    flags = new int[N*N];
    for (int i=0; i<N*N; i++) {
        flags[i] = 0;
    }
    flagIndex++;

    std::vector<PCL> PCL_list;

    for (int xSize=N-1; xSize>=0; xSize--) {
        for (int ySize=N-1; ySize>=0; ySize--) {
            for (int x = 0; x < N-xSize; x++) {
                for (int y = 0; y < N-ySize; y++) {
                    PCL pcl;
                    pcl.x1 = x;
                    pcl.y1 = y;
                    pcl.x2 = x + xSize;
                    pcl.y2 = y + ySize;
                    //detect if region is inside another PCL
                    int inside = 0;
                    for (int i=0; i<PCL_list.size(); i++) {
                        if (pcl.x1>=PCL_list[i].x1 && pcl.y1>=PCL_list[i].y1 && pcl.x2<=PCL_list[i].x2 && pcl.y2<=PCL_list[i].y2) {
                            inside = 1;
                            break;
                        }
                    }
                    if (inside) {
                        continue;
                    }
                    if (isPCL(pcl.x1, pcl.y1, pcl.x2, pcl.y2)) {
                        PCL_list.push_back(pcl);
                    }
                }
            }
        }
    }

    /*for (int i=0; i<PCL_list.size(); i++) {
        printf("%d %d %d %d\n", PCL_list[i].x1, PCL_list[i].y1, PCL_list[i].x2, PCL_list[i].y2);
    }*/
    
    printf("%d\n", PCL_list.size());
    fprintf(fileOut, "%d\n", PCL_list.size());
}
int isPCL(int x1, int y1, int x2, int y2) {
    //printf("--------------\n");
    //printf("x1: %d, y1: %d, x2: %d, y2: %d\n", x1, y1, x2, y2);
    flagIndex++;
    char col1 = '\0';
    char col2 = '\0';
    char spotCol = '\0';
    for (int j = y1; j <= y2; j++) {
        for (int i = x1; i <= x2; i++) {
            if (flags[j*N+i] == flagIndex) {
                continue;
            }
            if (col2) {
                if (spotCol) {
                    if (grid[j*N+i] == spotCol) {
                        continue;
                    }
                    else {
                        return 0;
                    }
                }
                if (grid[j*N+i] == col1) {
                    spotCol = col1;
                    continue;
                }
                else if (grid[j*N+i] == col2) {
                    spotCol = col2;
                    continue;
                }
                else {
                    return 0;
                }
            }

            std::stack<int> xStack;
            std::stack<int> yStack;
            xStack.push(i);
            yStack.push(j);
            char col = grid[N*j+i];
            while (!xStack.empty()) {
                int x = xStack.top();
                int y = yStack.top();
                //printf("x: %d, y: %d\n", x, y);
                flags[y*N+x] = flagIndex;
                if (grid[(y)*N+(x+1)] == col && flags[(y)*N+(x+1)] != flagIndex && x < x2) {
                    xStack.push(x+1);
                    yStack.push(y);
                    continue;
                }
                else if (grid[(y)*N+(x-1)] == col && flags[(y)*N+(x-1)] != flagIndex && x > x1) {
                    xStack.push(x-1);
                    yStack.push(y);
                    continue;
                }
                else if (grid[(y+1)*N+(x)] == col && flags[(y+1)*N+(x)] != flagIndex && y < y2) {
                    xStack.push(x);
                    yStack.push(y+1);
                    continue;
                }
                else if (grid[(y-1)*N+(x)] == col && flags[(y-1)*N+(x)] != flagIndex && y > y1) {
                    xStack.push(x);
                    yStack.push(y-1);
                    continue;
                }
                else {
                    xStack.pop();
                    yStack.pop();
                    continue;
                }
            }
            if (!col1) {
                col1 = col;
            }
            else {
                col2 = col;
            }
            //printf("found color\n");
        }
    }

    if (spotCol) {
        return 1;
    }
    else {
        return 0;
    }
}

