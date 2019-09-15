/*
 * ID: jhuang1
 * PROG: Grass Planting
 * LANG: C++11
 * RESULT: 1/10
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
	int cnt[N + 1];
	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		fin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}

	int ans = -1;

	for (int i = 1; i <= N; ++i) {
		ans = max(ans, cnt[i]);
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

