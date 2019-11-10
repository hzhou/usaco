/*
 * ID: jhuang1
 * PROG: Milk Measurement
 * LANG: C++11
<<<<<<< HEAD
 * RESULT: 8/11
 * TIME: 45 min
 * COMMENT: test1
=======
 * RESULT: 10/10
 * TIME: 45 min
 * COMMENT: No problems, just some minor syntax issues after first draft
>>>>>>> f9984f29666a11f13ab58868dc64b8ce0bcc038d
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
<<<<<<< HEAD

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
=======
 
using namespace std;
 
struct m {
  int d, c, g;
};

bool cotemp(const m& a, const m& b) {
	return a.d < b.d;
}
 
int main() {
	ifstream fin("measurement.in");
  	int N;
  	int G;
  	fin >> N >> G;
 
  	vector<m> list(N, {0});
  	for (int i = 0; i < N; ++i) {
    	cin >> list[i].d >> list[i].c >> list[i].g;
  	}
  	sort(list.begin(), list.end(), cotemp);
  	map<int, int, greater<int> > cnts;
  	cnts[0] = N + 1;
 
  	int ans = 0;
  	map<int, int> temp;
  	for (auto& m : list) {
            int& ref = temp[m.c];
    
            bool wastop = ref == cnts.begin()->first;
            int wascnt = cnts[ref]--;
            if (wascnt == 1) {
                    cnts.erase(ref);
            }
    
            ref += m.g;
    
            int iscnt = ++cnts[ref];
            bool istop = ref == cnts.begin() -> first;
            if (wastop) {
                    if (!istop || wascnt != 1 || iscnt != 1) {
                            ans++;
                    }
            } else if (istop) {
                    ans++;
            }
  	}
  	ofstream fout("measurement.out"); 
  	fout << ans;
 
  	return 0;
>>>>>>> f9984f29666a11f13ab58868dc64b8ce0bcc038d
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/

