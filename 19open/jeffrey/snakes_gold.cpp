/*
 * ID: jhuang1
 * PROG: Snakes
 * LANG: C++11
 * RESULT: 12/12
 * TIME: 85 min
 * COMMENT: Took a while to realize how to implement the DP in this question... but after that it was straightforward.
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

int main() {
	ifstream fin("snakes.in");
	int N, K;
	fin >> N >> K;
	vector<int> s(N + 1, 0);
	vector<int> dp((N + 1)*(N + 1), 0);
	int curr = 0, anss = 0;
	for (int i = 1; i <= N; ++i) {
		fin >> s[i];
		curr = max(curr, s[i]);
		dp[i * N] = i * curr;
		for (int j = 1; j <= N; ++j) {
			dp[i * N + j] = 2147483647;
			int c = s[i];
			for (int k = i - 1; k >= 0; --k) {
				dp[i * N + j] = min(dp[i * N + j], dp[k * N + j - 1] + c*(i - k));
				c = max(c, s[k]);
			}
		}
		anss += s[i];
	}
	
	ofstream fout("snakes.out");
	fout << dp[N * N + K] - anss;
	return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/

