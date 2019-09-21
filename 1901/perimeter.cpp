/*
 * ID: jhuang1
 * PROG: sample
 * LANG: C++11
 * RESULT: 9/11
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

/*int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};*/

int areas[1000000], perimeters[1000000];

void visit(vector<vector<int>>& board, vector<vector<int>> &visited, int i, int j, int num) {
	stack<pair<int, int>> go;
  	go.push(make_pair(i, j));
  	while (!go.empty()) {
    	auto current = go.top();
    	go.pop();
    	i = current.first; j = current.second;
    	if (visited[i][j] != 0 || board[i][j] == 0) continue;
    	visited[i][j] = num;
    	areas[num]++;
    	go.push(make_pair(i - 1,j));
    	go.push(make_pair(i + 1,j));
    	go.push(make_pair(i,j - 1));
    	go.push(make_pair(i,j + 1));
  	}
}

void perimeter(int N, vector<vector<int>> &visited) {
  	for (int i = 1; i <= N; ++i) {
    	for (int j = 1; j <= N; ++j) {
      		int r = visited[i][j];
      		if (r == 0) {
      			continue;
      		}
      		if (visited[i - 1][j]==0) {
      			perimeters[r]++;
      		}
      		if (visited[i + 1][j]==0) {
      			perimeters[r]++;
      		}
      		if (visited[i][j - 1]==0) {
      			perimeters[r]++;
      		}
      		if (visited[i][j + 1]==0) {
      			perimeters[r]++;
      		}
    	}
    }
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
	vector<int> row(N + 2, 0);
	vector<vector<int>> board(N + 2, row), visited(N + 2, row);
	for (int i = 1; i <= N; ++i) {
		fin >> a;
		for (int j = 1; j <= N; ++j) {
			if (a[j] == '#') {
				board[i][j] = 1;
			} else {
				board[i][j] = 0;
			}	
		}
	}

	int num = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] == 0 && board[i][j] == 1) {
				visit(board, visited, i, j, ++num);
			}
		}
	}

	perimeter(N, visited);

	int maxarea = -1, maxperi = -1;

	for (int i = 1; i <= num; ++i) {
    	if (areas[i] > maxarea || (areas[i] == maxarea && perimeters[i] < maxperi)) {
      		maxarea = areas[i];
      		maxperi = perimeters[i];
    	}
    }

	fout << maxarea << ' ' << maxperi;

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

