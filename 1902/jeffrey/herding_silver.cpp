/*
 * ID: jhuang1
 * PROG: Sleepy Cow Herding
 * LANG: C++11
 * RESULT: 12/12
 * TIME: 1ms
 * COMMENT: Worked, after some slight syntax issues
 * */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <chrono>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
	const char* FIN  = "herding.in";
	ifstream fin(FIN);

	//////////////////////////////////////
	// Start your solution from here...

	int N, line[100005];
	fin >> N;

	for (int i = 0; i < N; ++i) {
		fin >> line[i];
	}

	sort(line, line + N);

	int minV = 0, maxV = 0;

	maxV = max(line[N - 2] - line[0], line[N - 1] - line[1]) - (N - 2);

	if (line[N - 2] - line[0] == N - 2 && line[N - 1] - line[N - 2] > 2) {
		minV = 2;
	} else {
  		if (line[N - 1] - line[1] == N - 2 && line[1] - line[0] > 2) {
  			minV = 2;
  		} else {
  			int j = 0, best = 0;
  			for (int i = 0; i < N; ++i) {
    			while (j < N - 1 && line[j + 1] - line[i] <= N - 1) {
    				j++;
    			}
    			best = max(best, j - i + 1);
  			}
  			minV = N - best;
  		}
  	}

	// End of your soulution.
	//////////////////////////////////////
	const char* FOUT = "herding.out";
	ofstream fout(FOUT);
	fout << minV << endl << maxV;


	return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/
