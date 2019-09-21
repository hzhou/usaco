/*
 * ID: jhuang1
 * PROG: Fine Dining
 * LANG: C++11
 * RESULT: 8/10
 * TIME: 1ms
 * COMMENT: test1
 * */

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typdef make_pair(a, b) mp(a, b);
 
int n, m, k, hay[100000], y[100000];
vector<int> neighbors[100001];
map<pair<int,int>, int> val;
map<int,int> dist; 
set<pair<int,int>> visited;	
 
int main() {
    // INPUT
  	ifstream fin("dining.in");
  	fin >> n >> m >> k;
  	int a, b, t;
  	for (int i = 0; i < m; ++i) {
        fin >> a >> b >> t;
    	neighbors[a - 1].push_back(b - 1);
    	neighbors[b - 1].push_back(a - 1);
    	val[make_pair(a - 1, b - 1)] = t;
    	val[make_pair(b - 1, a - 1)] = t;
  	}
  	for (int i = 0; i < k; ++i) {
    	fin >> hay[i] >> y[i];
  	}

    // ALGORITHM

    for (int i = 0; i < k; ++i) {
        hay[i]--;
    }

  	visited.clear();
    visited.insert(make_pair(0, n - 1));
    while (!visited.empty()) {
        int i = visited.begin()->second;
        visited.erase(visited.begin());
        for (auto j : neighbors[i]) {
            if (dist.count(j) == 0 || dist[i] + val[make_pair(i, j)] < dist[j]) {
                dist[j] = dist[i] + val[make_pair(i, j)];
                visited.insert(make_pair(dist[j], j));
            }
        }
    }

  	map<int, int> odist = dist;

  	for (int i = 0; i < k; ++i) {
    	neighbors[n].push_back(hay[i]);
    	val[make_pair(n, hay[i])] = odist[hay[i]] - y[i];
  	}

  	dist.clear();
  	visited.clear();
    visited.insert(make_pair(0, n));
    while (!visited.empty()) {
      int i = visited.begin()->second;
      visited.erase(visited.begin());
      for (auto j : neighbors[i]) {
          if (dist.count(j) == 0 || dist[i] + val[make_pair(i, j)] < dist[j]) {
        dist[j] = dist[i] + val[make_pair(i, j)];
        visited.insert(make_pair(dist[j], j));
        }
      }
    }

    // OUTPUT

  	ofstream fout("dining.out");
  	for (int i = 0; i < n - 1; ++i) {
  		if (dist[i] <= odist[i]) {
    		fout << 1 << endl;
    	} else {
    		fout << 0 << endl;
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

