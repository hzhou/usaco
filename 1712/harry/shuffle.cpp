//Harry Zhou
//1 hour
// tried to use std::swap but didn't work
#include <cstdio>
int main() {
	FILE *fileIn= fopen("shuffle.in", "r");
    int cows;
    fscanf(fileIn, "%d", &cows);
	int shuffle[cows];
	for (int i=0; i<cows; ++i) {
		fscanf(fileIn, "%d", shuffle+i);
		shuffle[i] -= 1;
	}
	int idList[cows];
	for (int i=0; i<cows; ++i) {
		fscanf(fileIn, "%d", idList+i);
	}
    fclose(fileIn);
	
	int pos[cows];
	for (int i=0; i<cows; ++i) {
		pos[i] = i;
	}
	int posShuf[cows];
	int* pa = pos;
	int* pb = posShuf;
	for (int j=0; j<3; ++j) {
		for (int i=0; i<cows; ++i) {
			pb[shuffle[i]] = pa[i];
		}
		int *temp = pa;
		pa = pb;
		pb = temp;
	}
	int outList[cows];
	for (int i=0; i<cows; ++i) {
		outList[pa[i]] = idList[i];
	}
	
	FILE *fileOut = fopen("shuffle.out", "w");
	fprintf(fileOut, "%d\n", outList[0]);
	for (int i=1; i<cows; ++i) {
		fprintf(fileOut, "%d\n", outList[i]);
	}
    fclose(fileOut);
}
