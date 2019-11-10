/*
 * ID: jhuang1
 * PROG: Moocast
 * LANG: C++11
 * RESULT: 8/10
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

struct cow {
	int x, y;
};

int main() {
	ifstream fin("moocast.in");
	int N;
	fin >> N;
	vector<cow> cows(N);
	for (int i = 0; i < N; ++i) {
		fin >> cows[i].x >> cows[i].y; 
	}
	
	int dp[1000][1000];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + cows[i].x * cows[i].y;
		}
	}

	fout 
	ofstream fout("moocast.out");
	return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/

