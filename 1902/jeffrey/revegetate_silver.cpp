/*
 * ID: jhuang1
 * PROG: The Great Revegetation
 * LANG: C++11
 * RESULT: 12/12
 * TIME: 1ms
 * COMMENT: yay :)
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
int N, M, visited[100001];
bool works = true;
vector<int> S_nbrs[100001], D_nbrs[100001];

void visit(int x, int v) {
  	visited[x] = v;
  	for (auto i: S_nbrs[x]) {
    	if (visited[i] == 3 - v) {
    		works = false; 
    	}
    	if (visited[i] == 0) {
    		visit(i, v);
    	}
  	}
  	for (auto i : D_nbrs[x]) {
    	if (visited[i] == v) {
    		works = false; 
    	}
    	if (visited[i] == 0) {
    		visit(i, 3 - v);
    	}
 	}  
}

int main(int argc, char* argv[]) {
	const char* FIN  = "revegetate.in";
	const char* FOUT = "revegetate.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int N, M;
	fin >> N >> M;

	char c;
	int a, b;

	for (int i = 0; i < M; ++i) {
		fin >> c >> a >> b;
		if (c == 'S') {
			S_nbrs[a].push_back(b);
			S_nbrs[b].push_back(a);
		} else {
			D_nbrs[a].push_back(b);
			D_nbrs[b].push_back(a);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (visited[i] == 0) {
			ans++;
			visit(i, 1);
		}
	}
	if (!works) {
		fout << "0";
	} else {
    	fout << "1";
    	for (int i = 0; i < ans; ++i) {
    		fout << "0";
    	}
    }

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
