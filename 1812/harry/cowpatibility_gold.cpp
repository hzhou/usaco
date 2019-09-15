//Harry Zhou
//9-14-2019
//1hr
//I got all tests right except 10 at around 50min
//Turns out the problem was integer overflow
//I figured out the overflow problem pretty quickly but I wasted quite a bit of time figuring out that that I needed to turn %d to %ld in the input and not just the output
//Other than that, most of the time was spent working out the math
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;
typedef std::map<int,int> imap;
typedef std::vector<int> ivec;
typedef std::stack<int> istack;
typedef std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

int main() {
    FILE *fin = fopen("cowpatibility.in", "r");
    FILE *fout = fopen("cowpatibility.out", "w");

    int64_t N;
    fscanf(fin, "%ld", &N);
    int64_t preferences[50000][5];
    for (int64_t i=0; i<N; i++) {
        for (int64_t j=0; j<5; j++) {
            fscanf(fin, "%ld", &preferences[i][j]);
        }
        std::sort(preferences[i], preferences[i]+5);
    }

    std::map<ivec, int64_t> c1;
    std::map<ivec, int64_t> c2;
    std::map<ivec, int64_t> c3;
    std::map<ivec, int64_t> c4;
    std::map<ivec, int64_t> c5;
    for (int64_t i=0; i<N; i++) {
        for (int64_t a=0; a<5; a++) {
            ivec v1{preferences[i][a]};
            c1[v1]++;
            for (int64_t b=a+1; b<5; b++) {
                ivec v2{preferences[i][a], preferences[i][b]};
                c2[v2]++;
                for (int64_t c=b+1; c<5; c++) {
                    ivec v3{preferences[i][a], preferences[i][b], preferences[i][c]};
                    c3[v3]++;
                    for (int64_t d=c+1; d<5; d++) {
                        ivec v4{preferences[i][a], preferences[i][b], preferences[i][c], preferences[i][d]};
                        c4[v4]++;
                        for (int64_t e=d+1; e<5; e++) {
                            ivec v5{preferences[i][a], preferences[i][b], preferences[i][c], preferences[i][d], preferences[i][e]};
                            c5[v5]++;
                        }
                    }
                }
            }
        }
    }

    int64_t nc1 = 0;
    int64_t nc2 = 0;
    int64_t nc3 = 0;
    int64_t nc4 = 0;
    int64_t nc5 = 0;
    for (auto itr = c1.begin(); itr != c1.end(); itr++) {
        nc1 += itr->second * (itr->second - 1) / 2;
    }
    for (auto itr = c2.begin(); itr != c2.end(); itr++) {
        nc2 += itr->second * (itr->second - 1) / 2;
    }
    for (auto itr = c3.begin(); itr != c3.end(); itr++) {
        nc3 += itr->second * (itr->second - 1) / 2;
    }
    for (auto itr = c4.begin(); itr != c4.end(); itr++) {
        nc4 += itr->second * (itr->second - 1) / 2;
    }
    for (auto itr = c5.begin(); itr != c5.end(); itr++) {
        nc5 += itr->second * (itr->second - 1) / 2;
    }

    int64_t compatible = nc1 - nc2 + nc3 - nc4 + nc5;
    int64_t incompatible = N*(N-1)/2 - compatible;
    
    printf("%ld\n", incompatible);
    fprintf(fout, "%ld\n", incompatible);
}
