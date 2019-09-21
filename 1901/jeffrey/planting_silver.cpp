/*
 * ID: jhuang1
 * PROG: Grass Planting
 * LANG: C++11
 * RESULT: 10/10
 * TIME: 1ms
 * COMMENT: test1
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
	const char* FIN  = "planting.in";
	const char* FOUT = "planting.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int N;
	fin >> N;
	unordered_map<int, int> cnt;
	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		fin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}

	int ans = -1;

	for (auto i: cnt) {
		if (i.first != 0) {
			ans = max(ans, i.second);
		}
	}
	ans++;
	fout << ans;

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

