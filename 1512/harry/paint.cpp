//Harry Zhou
//5 min
//*presses staples button* That was easy!
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("paint.in", "r");
    FILE *fileOut = fopen("paint.out", "w");

    int a, b, c, d;
    fscanf(fileIn, "%d %d %d %d", &a, &b, &c, &d);

    int ans = b-a + d-c;
    int intersect = std::max( 0 , std::min(b,d)-std::max(a,c) );
    ans -= intersect;

    printf("%d\n", ans);
    fprintf(fileOut, "%d\n", ans);
}
