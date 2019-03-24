//Harry Zhou
//15 min
//Didn't see that it needed a square rather than a rectangle at first
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("square.in", "r");

    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    fscanf(fileIn, "%d %d %d %d %d %d %d %d", &ax1, &ay1, &ax2, &ay2, &bx1, &by1, &bx2, &by2);

    int x1 = std::min(ax1, bx1);
    int y1 = std::min(ay1, by1);

    int x2 = std::max(ax2, bx2);
    int y2 = std::max(ay2, by2);

    //printf("%d %d %d %d\n", x1, y1, x2, y2);

    int length = std::max( x2-x1, y2-y1 );
    int area = length*length;
    
    //printf("%d\n", area);
    FILE *fileOut = fopen("square.out", "w");
    fprintf(fileOut, "%d\n", area);
}
