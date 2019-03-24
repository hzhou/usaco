#include <cstdio>
#include <algorithm>
int main() {
	FILE *fileIn = fopen("measurement.in", "r");
	
	int N;
	fscanf(fileIn, "%d", &N);
	printf("%d\n", N);
	
	int cows[3] = {7, 7, 7};
	int cowd[3] = {1, 1, 1};
	int *day = new int[N];
	char **name = new char*[N];
	int *change = new int[N];
	for (int i=0; i<N; ++i) {
		name[i] = new char[10];
	}
	for (int i = 0; i < N; i++) {
		fscanf(fileIn, "%d %s %d", day+i, name[i], change+i);
	}
	
	fclose(fileIn);
	
	for (int i=0; i<N-1; ++i) {
		int min = day[i];
		int minInd = i;
		for (int j=i+1; j<N; ++j) {
			if (day[j]<day[minInd]) {
				min = day[j];
				minInd = j;
			}
		}
		std::swap(day[i],day[minInd]);
		printf("%d %d\n", i, minInd);
		std::swap(name[i],name[minInd]);
		std::swap(change[i],change[minInd]);
	}
	
	for (int i=0; i<N; ++i) {
		printf("%d %s %d\n", day[i], name[i], change[i]);
	}
	
	int changeNum = 0;
	for (int i=0; i<N; ++i) {
		
		if (name[i][0] == 'B') {
			cows[0] += change[i];
		}
		if (name[i][0] == 'E') {
			cows[1] += change[i];
		}
		if (name[i][0] == 'M') {
			cows[2] += change[i];
		}
		
		int max;
		if (cows[0] > cows[1])
			max = cows[0];
		else
			max = cows[1];
		if (cows[2] > max)
			max = cows[2];
		
		int changed = 0;
		for (int i=0; i<3; i++) {
			int disp;
			if (cows[i] == max) {
				disp = 1;
			}
			else
				disp = 0;
			if (!(disp == cowd[i])) {
				changed = 1;
			}
			cowd[i] = disp;
		}
		printf("Max: %d\nCow List: %d, %d, %d\nCowD List: %d, %d, %d\n\n", max, cows[0], cows[1], cows[2], cowd[0], cowd[1], cowd[2]);
		if (changed) {
			++changeNum;
		}
		
	}
	
	printf("%d\n", changeNum);
	
	FILE *fileOut = fopen("measurement.out", "w");
    fprintf(fileOut, "%d\n", changeNum);
    fclose(fileOut);
	
}
