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

int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

pair<int, int> comp(vector<vector<int>>& board, vector<vector<bool>> &visited, int r, int c, pair<int, int> ap) {
	if (r < 0 || c < 0 || r >= board.size() || c >= board.size()) {
		return make_pair(0, 0);
	}
	if (visited[r][c]) {
		return make_pair(0, 0);
	}
	visited[r][c] = true;
	int newr = r;
	int newc = c;
	int per = 4;
	ap.second += per;
	pair<int, int> res;
	for (int i = 0; i < 4; ++i) {
		newr += mx[i];
		newc += my[i];
		if (newr < 0 || newc < 0 || newr >= board.size() || newc >= board.size()) {
			continue;
		}
		if (visited[newr][newc]) {
			continue;
		}
		if (board[newr][newc] == 1) {
			ap.second--;
			res = comp(board, visited, newr, newc, ap);
			ap.first += res.first;
			ap.second += res.second;
		}
	}
	return ap;
}

int main(int argc, char* argv[]) {
	const char* FIN  = "perimeter.in";
	const char* FOUT = "perimeter.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int N;
	fin >> N;
	string a;
	vector<int> row(N, 0);
	vector<vector<int>> board(N, row);
	vector<bool> ro(N, false);
	vector<vector<bool>> visited(N, ro);
	for (int i = 0; i < N; ++i) {
		fin >> a;
		for (int j = 0; j < N; ++i) {
			if (a[j] == '#') {
				board[i][j] = 1;
			} else {
				board[i][j] = 0;
			}
		}
	}

	vector<pair<int, int>> res;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!visited[i][j] && board[i][j]) {
				res.push_back(comp(board, visited, i, j, make_pair(0, 0)));
			}
		}
	}

	sort(res.begin(), res.end());

	fout << res.rbegin()->first << res.rbegin()->second;

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

