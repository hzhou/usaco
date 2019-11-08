/*
 * ID: jhuang1
 * PROG: Counting Haybales
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

int compSum(vector<int> hay, int val) {
	if(hay[0] > val) {
		return 0;
	}
	int min = 0;
	int max = hay.size() - 1;
	while(min != max) {
		int mid = (min+max+1)/2;
		if(hay[mid] <= val) {
			min = mid;
		}
		else {
			max = mid-1;
		}
	}
	return min + 1;
}


int main(int argc, char* argv[]) {
	const char* FIN  = "haybales.in";
	const char* FOUT = "haybales.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	int N, Q;

	fin >> N >> Q;

	vector<int> hay(N, 0);

	for (int i = 0; i < N; ++i) {
		fin >> hay[i];
	}

	sort(hay.begin(), hay.end());
	int i = 0;
	for (int i = 0; i < Q; ++i) {
		int a, b;
		fin >> a >> b;
		int qu = compSum(hay, b) - compSum(hay, a - 1);
		fout << qu << endl;
	}

	return 0;
}

