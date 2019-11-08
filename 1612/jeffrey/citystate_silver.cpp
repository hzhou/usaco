/*
 * ID: jhuang1
 * PROG: Cities and States
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

int main(int argc, char* argv[]) {
	const char* FIN  = "citystate.in";
	const char* FOUT = "citystate.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int N;

	fin >> N;

	string a, b, c;

	map<string, long long> sc;

	for (int i = 0; i < N; ++i) {
		fin >> a >> b;
		if (a.substr(0, 2) != b) {
			c = a.substr(0, 2);
			c += b;
			sc[c]++;
		}
	}

	int ans = 0;

	for (auto i: sc) {
		string s2 = i.first;
		swap(s2[0], s2[2]);
		swap(s2[1], s2[3]);
		if (sc[s2] > 0) {
			ans += i.second * sc[s2];
		}
	}

	ans /= 2;

	fout << ans;
	// End of your soulution.
	//////////////////////////////////////

	return 0;
}


