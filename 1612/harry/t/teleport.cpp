//Harry Zhou
//12 min
//All tests successful
#include <cstdio>
#include <algorithm>
int main() {
    FILE *fileIn = fopen("teleport.in", "r");

    int a, b, x, y;
    fscanf(fileIn, "%d %d %d %d", &a, &b, &y, &x);

    int dist1 = std::abs(a-b);
    int dist2 = std::abs(a-x) + std::abs(b-y);
    int dist3 = std::abs(a-y) + std::abs(b-x);

    int shortest = std::min(std::min(dist1, dist2), dist3);
    printf("%d\n", shortest);

    FILE *fileOut = fopen("teleport.out", "w");
    fprintf(fileOut, "%d\n", shortest);
}
