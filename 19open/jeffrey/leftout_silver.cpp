/*
 * ID: jhuang1
 * PROG: Left Out
 * LANG: C++11
 * RESULT: 12/12
 * TIME: 75 min
 * COMMENT: Had some syntax/compilation errors at first, but got working in ~20 min after first submission
 * */
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int check(int N, vector<int>& grid, int i, int j, int ii, int jj, int c) {
	int ret = 0;
	for (int k = i; k <= ii; ++k) {
		for (int m = j; m <= jj; ++m) {
			if (grid[k * N + m] == c) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {
	int N;
	ifstream fin("leftout.in");
	string hi;
	fin >> N;
	vector<int> grid(N * N);
	for (int i = 0; i < N; ++i) {
		fin >> hi;
		for (int j = 0; j < N; ++j) {
			grid[i * N + j] = (hi[j]=='L');
		}
	}

	for (int i = 1; i < N; ++i) {
		grid[i * N] = grid[i * N] ^ grid[0];
		for (int j = 1; j < N; ++j) {
			grid[i * N + j] = grid[i * N + j] ^ grid[j] ^ grid[i * N];
		}
	}

	ofstream fout("leftout.out");

	if (check(N, grid, 1, 1, N - 1, N - 1, 0) == 0) { 
		fout << 1 << ' ' << 1 << endl; 
		return 0; 
	}
	if (check(N, grid, 1, 1, N - 1, N - 1, 1) == N - 1) {
		for (int j = 1; j < N; ++j) {
			if (check(N, grid, 1, j, N - 1, j, 1) == N - 1) { 
				fout << 1 << " " << j + 1 << endl; 
				return 0; 
			}
		}
		for (int i = 1; i < N; ++i) {
			if (check(N, grid, i, 1, i, N - 1, 1) == N - 1) { 
				fout << i + 1 << " " << 1 << endl; 
				return 0; 
			} 
		}
		fout << "-1" << endl; 
		return 0;
	}
	if (check(N, grid, 1, 1, N - 1, N - 1, 1) != 1) { 
		fout << "-1" << endl; 
		return 0; 
	} 
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (grid[i * N + j] == 1) { 
				fout << i + 1 << " " << j + 1 << endl; 
			}
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

