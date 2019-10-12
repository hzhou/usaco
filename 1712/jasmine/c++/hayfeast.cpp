//Jasmine Zhang
//1 hour
//10/10 cases passed
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int main () {
    FILE * In = fopen("hayfeast.in", "r");
    long long N, M; 
    fscanf(In, "%lld %lld", &N, &M);
    
    long long flavor [N];
    long long spiciness [N];
    for (int i = 0; i < N; i++) 
        fscanf(In, "%lld %lld", &flavor[i], &spiciness[i]);
    
    int b = 0;
    int e = 0;
    long long minSpice = -1;
    long long totalFlav = 0;
    map <long long, long long, greater <long long> > spice;  //stores current spiciness levels to keep track of max
    while (e < N) {
        while (e < N && totalFlav < M) {
            totalFlav += flavor[e];
            spice[spiciness[e]] += 1; 
            //cout << totalFlav << "s\n";
            e++;
        }
        if (totalFlav < M)
            break;

        //cout << totalFlav << "\n"; 
        long long maxSpice = spice.begin()->first;
        //cout << maxSpice << "\n";
        if (maxSpice < minSpice || minSpice == -1)
            minSpice = maxSpice;
        spice[spiciness[b]] -= 1;
        if (spice[spiciness[b]]== 0)
            spice.erase(spiciness[b]);
            
        totalFlav -= flavor[b];
        b++;
        //cout << totalFlav << "b\n"; 
        
    }
    FILE * Out = fopen ("hayfeast.out", "w");
    fprintf(Out, "%lld\n", minSpice);
    cout << minSpice; 

    return 0;
}