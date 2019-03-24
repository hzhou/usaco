//Harry Zhou
//55 min
//used VIM this time
#include <cstdio>
#include <algorithm>
int main() {
    FILE *fileIn = fopen("billboard.in", "r");
    
    int Ax1, Ay1, Ax2, Ay2;
    int Bx1, By1, Bx2, By2;
    fscanf(fileIn, "%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);
    fscanf(fileIn, "%d %d %d %d", &Bx1, &By1, &Bx2, &By2);

    int blockX = 0;
    int blockY = 0;
    int area;
    if (Ax1 >= Bx1 && Ax2 <= Bx2) {
        blockX = 1;
    }
    if (Ay1 >= By1 && Ay2 <= By2) {
        blockY = 1;
    }

    if (blockX && blockY) {
        area = 0;
    }
    else if (blockX) {
        int yOb = std::max( 0 , std::min(Ay2-By1,By2-Ay1) );
        if (By1>Ay1 && By2 < Ay2) {
            yOb = 0;
        }
        area = (Ax2-Ax1) * (Ay2-Ay1 - yOb);
    }
    else if (blockY) {
        int xOb = std::max( 0 , std::min(Ax2-Bx1,Bx2-Ax1) );
        if (Bx1>Ax1 && Bx2 < Ax2) {
            xOb = 0;
        }
        area = (Ax2-Ax1 - xOb) * (Ay2-Ay1);
    }
    else {
        area = (Ax2-Ax1) * (Ay2-Ay1);
    }
    printf("%d\n",area);

    FILE *fileOut = fopen("billboard.out", "w");
    fprintf(fileOut, "%d\n", area);
}
