/*
 * ID: jhuang1
 * PROG: sample
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

struct pie {
	int b, e;
	pie(int c, int d) {
		b = c;
		e = d;
	}
};

int main() {
	ifstream fin("piepie.in");
	int N, D;
	fin >> N >> D;
	multiset<pie> bessie, elise;
	pie in;
	for (int i = 0; i < N; ++i) {
		fin >> in.b >> in.e;
		bessie.insert(in);
	}
	for (int i = 0; i < N; ++i) {
		fin >> in.b >> in.e;
		elise.insert(in);
	}

	pie curr_p(0, 0);

	ofstream fout("piepie.out");

	for (int i = 0; i < N; ++i) {
		auto lowest_pie = lower_bound(bessie.begin(), bessie.end(), curr_p + D);
		lowest_pie--;
		if (lowest_pie->b < curr_p.b) {
			fout << -1 << endl;
			continue;
		}
	}

	return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/

