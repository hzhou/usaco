//Jasmine Zhang
//1.5 hours
//9/10 cases passed
//Most time spent on figuring out string properties in c++
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int N, M; 
bool canTell (int l, string spotty [], string plain []);

int main () {
    FILE * In = fopen("cownomics.in", "r");
    fscanf(In, "%d %d", &N, &M);

    string spotty [N];
    for (int i = 0; i < N; i++) {
        char s [M];
        fscanf(In,  "%s", &s);
        spotty[i] = (s); //built in constructor that converts char array to string 
    }

    string plain [N];
    for (int i = 0; i < N; i++) {
        char s [M];
        fscanf(In,  "%s", &s);
        plain[i] = (s); 
    }

    int b = 1;
    int e = M;

    while (b <= e) {
        int m = (b+e)/2;
        bool cT = canTell(m, spotty, plain);
        if (cT)
            e = m - 1;
        else 
            b = m + 1;
        //cout << m << " " << cT << "\n";
    }
    
    cout << b;
    FILE * Out = fopen ("cownomics.out", "w");
    fprintf(Out, "%d\n", b);

    return 0; 
}
bool canTell (int l, string spotty [], string plain []) {
    for (int i = 0; i <= M - l; i++) {
        unordered_set <string> spot;
        for (int j = 0; j < N; j++) 
            spot.insert(spotty[j].substr(i, l)); //substr is (index, length)
        //cout << "\n";
        
        bool b = true;
        for (int j = 0; j < N; j++) {
            string p = plain[j].substr(i, l);
            if (spot.find(p) != spot.end()) {
                b = false;
                break;
            }
        }
        if (b)
            return true;
    }
    return false;
}