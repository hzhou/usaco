/*
 * ID: jhuang1
 * PROG: My Cow Ate My Homework
 * LANG: C++11
 * RESULT: 10/10
 * TIME: 30 min
 * COMMENT: simple DP, wouldn't work at first due to integer overflow, so switching to long long made it work
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

void check() {

}

int main() {
	ifstream fin("homework.in");
	int N;
	fin >> N;
	long long s[N + 1], mins[N + 1], maxs[N + 1];
	for (int i = 1; i <= N; ++i) {
		fin >> s[i];
	}
	mins[N] = s[N];
	maxs[N] = s[N];
	for (int i = N - 1; i >= 0; --i) {
		maxs[i] = maxs[i + 1] + s[i];
    	mins[i] = min(mins[i + 1], s[i]);
	}

	long long num = 0, den = 1;
  
  	for (int i = 1; i <= N - 2; ++i) {
    	if ((maxs[i + 1] - mins[i + 1]) * den > num * (N - i - 1)) {
     		num = maxs[i + 1] - mins[i + 1];
     		den = N - i - 1;
    	}	
    }

    ofstream fout("homework.out");
  
  	for (int i = 1; i <= N - 2; ++i) {
    	if ((maxs[i + 1] - mins[i + 1]) * den == num * (N - i - 1)) {
      		fout << i << endl;
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

