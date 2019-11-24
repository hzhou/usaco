//Jasmine Zhang
//2.5 hours
//2/10 cases passed
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct State { 
    int index;
    int iStep; //this matters
    //doesn't matter what direction you come from, 
    //int dir 
    long long time;
    //kind of like java constructor? 
    State(int index, int iStep, long long time) 
        : index(index), iStep(iStep), time(time)
    { 
        // printf("push %d - %d - %lld\n", index, iStep, time);
    }
}; 
struct CompareState { 
    bool operator()(State const& s1, State const& s2) 
    { 
        //greater to pop least time first
        return s1.time > s2.time; 
    } 
}; 
int main () {
    FILE * In = fopen("visitfj.in", "r");
    int N, T;
    fscanf(In, "%d %d", &N, &T);

    int fields [N*N];
    //a different ith%3 step is a different state
    long long sPath [N*N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           fscanf(In, "%d", &fields[i*N+j]); 
           fill_n(sPath[i*N+j], 3, -1);
        }
    }
    
    //shortest path
    priority_queue<State, vector<State>, CompareState> pq;
    pq.push({0,0,0});
    //long long min = -1; 
    
    while(!pq.empty()) {
        State current = pq.top();
        pq.pop();
        if (sPath[current.index][current.iStep%3] != -1 && current.time >= sPath[current.index][current.iStep%3])
            continue;
        else 
            sPath[current.index][current.iStep%3] = current.time;

        printf("%d - %lld - %d\n", current.index, current.time, current.iStep % 3);

        int i = current.index/N;
        int j = current.index%N;

        
        if (i > 1) {
            int a = T;
            if (current.iStep % 3 == 2)
                a += fields[(i-1)*N+j]; 
            pq.push({(i-1)*N+j,current.iStep+1,current.time+a});
        }
        
        if (i < N-1) {
            int a = T;
            if (current.iStep % 3 == 2)
                a += fields[(i+1)*N+j]; 
            pq.push({(i+1)*N+j,current.iStep+1,current.time+a});
        }
        
        if (j > 1) {
            int a = T;
            if (current.iStep % 3 == 2)
                a += fields[i*N+j-1]; 
            pq.push({i*N+j-1,current.iStep+1,current.time+a});
        }
        if (j < N-1) {
            int a = T;
            if (current.iStep % 3 == 2)
                a += fields[i*N+j+1]; 
            pq.push({i*N+j+1,current.iStep+1,current.time+a});
        }
        
    }
    
    long long minT = min(sPath[N*N-1][0], min (sPath[N*N-1][1], sPath[N*N-1][2]));
    cout << minT <<"\n";
    FILE * Out = fopen ("visitfj.out", "w");
    fprintf(Out, "%lld\n", minT);

    return 0;
}
