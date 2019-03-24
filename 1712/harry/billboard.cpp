#include <cstdio>
int min(int a, int b) {
	return !(a>b) ? a : b;
}
int max(int a, int b) {
	return a>b ? a : b;
}
int main() {
        FILE *fileIn= fopen("billboard.in", "r");
        int a1x, a1y, a2x, a2y, b1x, b1y, b2x, b2y, c1x, c1y, c2x, c2y; //a2x > a1x
        fscanf(fileIn, "%d %d %d %d %d %d %d %d %d %d %d %d", &a1x, &a1y, &a2x, &a2y, &b1x, &b1y, &b2x, &b2y, &c1x, &c1y, &c2x, &c2y);
        fclose(fileIn);
		
		int area = (a2x-a1x)*(a2y-a1y) + (b2x-b1x)*(b2y-b1y);

		int axMax = max(a1x,c1x);
		int axMin = min(a2x,c2x);
		
		int ayMax = max(a1y,c1y);
		int ayMin = min(a2y,c2y);
		
		int axDif = axMin - axMax;
		int ayDif = ayMin - ayMax;
		if (axDif > 0 && ayDif > 0) {
			area -= axDif*ayDif;
		}
		
		int bxMax = max(b1x,c1x);
		int bxMin = min(b2x,c2x);
		
		int byMax = max(b1y,c1y);
		int byMin = min(b2y,c2y);
		
		int bxDif = bxMin - bxMax;
		int byDif = byMin - byMax;
		if (bxDif > 0 && byDif > 0) {
			area -= bxDif*byDif;
			
		}
		printf("%d\n",area);

        FILE *fileOut = fopen("billboard.out", "w");
        fprintf(fileOut, "%d\n", area);
        fclose(fileOut);
}

