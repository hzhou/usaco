/*
 * ID: jhuang1
 * PROG: Cow Steeplechase II
 * LANG: C++11
 * RESULT: 1/12
 * TIME: 47 min
 * COMMENT: Wasn't sure why program was not adjusting to test cases...
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

double x;

struct Point { 
    long long x, y; 
    int s_ind; 
};
struct Segment { 
    Point p, q; 
    int ind; 
};

bool operator< (Point p1, Point p2) { 
    if (p1.x == p2.x) {
        return p1.y < p2.y; 
    } 
    return p1.x < p2.x; 
}

int sign(long long x) { 
    if (x == 0) {
        return 0; 
    } else {
        if (x < 0) {
            return -1;
        }
        return 1;
    }
}
int operator* (Point p1, Point p2) { 
    return sign(p1.x * p2.y - p1.y * p2.x); 
}

Point operator- (Point p1, Point p2) { 
    Point p = {p1.x - p2.x, p1.y - p2.y}; 
    return p; 
}

bool inter(Segment &s1, Segment &s2) {
  Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
  return ((q2 - p1) * (q1 - p1)) * ((q1 - p1) * (p2 - p1)) >= 0 && ((q1 - p2) * (q2 - p2)) * ((q2 - p2) * (p1 - p2)) >= 0;
}

double evlu(Segment s) {
    if (s.p.x == s.q.x) {
        return s.p.y;
    }
    return s.p.y + (s.q.y - s.p.y) * (x - s.p.x) / (s.q.x - s.p.x);
}

bool operator< (Segment s1, Segment s2) { 
    return s1.ind != s2.ind && evlu(s1) < evlu(s2); 
}

bool operator== (Segment s1, Segment s2) { 
    return s1.ind == s2.ind; 
}

int main() {
    ifstream fin("cowjump.in");
    int N;
    vector<Segment> S;
    vector<Point> P;
    fin >> N;
    Segment s;
    for (int i = 0; i < N; ++i) {
        fin >> s.p.x >> s.p.y >> s.q.x >> s.q.y;
        s.ind = s.p.s_ind = s.q.s_ind = i;
        S.push_back(s);
        P.push_back(s.p); 
        P.push_back(s.q);
    }

    sort(P.begin(), P.end());

    set<Segment> active;
    int ans1 = 0, ans2 = 0; 
    for (int i = 0; i < N * 2; ++i) {
        ans1 = P[i].s_ind; 
        x = P[i].x;
        auto it = active.find(S[ans1]);
        if (it != active.end()) {
            auto after = it, before = it; 
            after++;
            if (before != active.begin() && after != active.end()) {
                before--;
                if (inter(S[before->ind], S[after->ind])) { 
                    ans1 = before->ind; ans2 = after->ind; 
                    break; 
                }
            }
            active.erase(it);
        } else {
            auto it = active.lower_bound(S[ans1]);
            if (it != active.end() && inter(S[it->ind], S[ans1])) { 
                ans2 = it->ind; 
                break; 
            }
            if (it != active.begin()) { 
                it--; 
                if (inter(S[it->ind], S[ans1])) { 
                    ans2 = it->ind; break; 
                } 
                active.insert(S[ans1]);
            }
        } 
    }
    if (ans1 > ans2) {
        swap(ans1, ans2);
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i].ind != ans2 && inter(S[i], S[ans2])) {
            cnt++;
        }
    }

    ofstream fout("cowjump.out");
    fout << (cnt > 1 ? ans2 + 1 : ans1 + 1) + 1 << endl;

    /*if (cnt > 1) {
        fout << ans2 + 1;
    } else {
        fout << ans1 + 1;
    }*/
    return 0;
}

/*
Instructions:
git add dining_gold.cpp
git commit
git push
*/
