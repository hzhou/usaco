//Harry Zhou
//1 hour 10 min
//9-21-2019
//At about 30 minutes I could pass all tests except 2 and 8
//That code used std::lower_bound (O(logn)) time complexity) to find the insertion position and std::rotate (O(n)) to shuffle it in
//In order to pass all tests I had to rewrite most of my program to use a BIT
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>


using std::cout;
using std::endl;

typedef long long int LL;

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;
typedef std::map<int,int> imap;
typedef std::vector<int> ivec;
typedef std::stack<int> istack;
typedef std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

int N;

int BIT[100001];
int sum(int idx) {
    int sum=0;
    idx++;
    while (idx>0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int val) {
    idx++;
    while (idx<=N) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {
    std::ifstream fin;
    fin.open("sleepy.in");
    std::ofstream fout;
    fout.open("sleepy.out");

    fin >> N;
    
    int *order = new int[N];
    for (int i=0; i<N; i++) {
        fin >> order[i];
        order[i]--;
    }

    for (int i=0; i<=N; i++) {
        BIT[i] = 0;
    }

    int list_start = 0;
    for (int i=N-1; i>=1; i--) {
        if (order[i-1] > order[i]) {
            list_start = i;
            break;
        }
    }

    for (int i=list_start; i<N; i++) {
        update(order[i], 1);
    }

    ivec steps;
    for (int i=0; i<list_start; i++) {
        steps.push_back(list_start-i-1 + sum(order[i]));
        update(order[i],1);
    }
    
    cout << list_start << endl;
    fout << list_start << endl;
    for (int i = 0; i<list_start-1; i++) {
        cout << steps[i] << " ";
        fout << steps[i] << " ";
    }
    cout << steps[list_start-1] << endl;
    fout << steps[list_start-1] << endl;
}
