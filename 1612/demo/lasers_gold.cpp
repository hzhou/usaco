#include <vector>
#include <unordered_set>
#include <cstdio>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int count;

    FILE* In = fopen("lasers.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int xL;
    int yL;
    int xB;
    int yB;
    fscanf(In, " %d %d %d %d %d" ,&N,&xL,&yL,&xB,&yB);
    int X[N];
    int Y[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&X[i],&Y[i]);
    }
    fclose(In);
    std::multimap<int,int> Mx;
    std::multimap<int,int> My;
    for (int  i = 0; i<N; i++) {
        Mx.insert(std::pair < int, int > (X[i], i));
        My.insert(std::pair < int, int > (Y[i], i));
    }
    std::unordered_set<int> cache;
    std::vector<int> Q;
    if (cache.count(yL) == 0) {
        Q.push_back(yL);
        cache.insert(yL);
    }
    if (cache.count(xL + 1000000000) == 0) {
        Q.push_back(xL + 1000000000);
        cache.insert(xL + 1000000000);
    }
    count = 0;
    while (Q.size() > 0) {
        std::vector<int> Q2;
        for(auto n : Q){
            if (count < 3) {
                std::cout<<"count="<<count<<", "<<"n="<<n<<'\n';
            }
            if (n < 1000000000) {
                if (n == yB) {
                    goto done;
                }
                auto r = My.equal_range(n);
                for (auto it=r.first; it!=r.second; ++it) {
                    if (cache.count(X[it->second] + 1000000000) == 0) {
                        Q2.push_back(X[it->second] + 1000000000);
                        cache.insert(X[it->second] + 1000000000);
                    }
                }
            } else {
                if (n == xB + 1000000000) {
                    goto done;
                }
                auto r = Mx.equal_range(n-1000000000);
                for (auto it=r.first; it!=r.second; ++it) {
                    if (cache.count(Y[it->second]) == 0) {
                        Q2.push_back(Y[it->second]);
                        cache.insert(Y[it->second]);
                    }
                }
            }
        }
        count++;
        Q = Q2;
    }
    count = -1;
    done:
        std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("lasers.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
