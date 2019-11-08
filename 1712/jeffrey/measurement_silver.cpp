/*
 * ID: jhuang1
 * PROG: Milk Measurement
 * LANG: C++11
 * RESULT: 8/11
 * TIME: 45 min
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

struct m {
	int d, c, g;
};

bool comp(const m& a, const m& b) {
	return a.d < b.d;
}

int main(int argc, char* argv[]) {
	ifstream fin("measurement.in");
	int N, G;
	fin >> N >> G;
	vector<m> log(N);
	for (int i = 0; i < N; ++i) {
		cin >> log[i].d >> log[i].c >> log[i].g;
	} 
	sort(log.begin(), log.end(), comp);
	map<int, int, greater<int> > cnt;
	cnt[0] = N + 1;

	ofstream fout("measurement.out");
	return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/

