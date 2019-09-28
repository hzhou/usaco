/*
 * ID: jhuang1
 * PROG: Painting The Barn
 * LANG: C++11
 * RESULT: 10/10
 * TIME: 1ms
 * COMMENT: No problems! DP, kind of.
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
	const char* FIN  = "paintbarn.in";
	const char* FOUT = "paintbarn.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int N, K;

	fin >> N >> K;

	vector<int> row(1001, 0);
	vector<vector<int>> wall(1001, row); 

	int x1, x2, y1, y2;

	for (int i = 0; i < N; ++i) {
		fin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i) {
			wall[i][y1]++;
			wall[i][y2]--;
		}
	}

	int ans = 0;

	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			if (wall[i][j] == K) {
				ans++;
			}
			wall[i][j + 1] += wall[i][j];
		}
	}

	fout << ans <<endl;

	// End of your soulution.
	//////////////////////////////////////

	return 0;
}



/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/



