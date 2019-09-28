#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <algorithm> //sort

using namespace std;
struct flavComb {
    int n; 
    int flav [5] = {0}; 
};

// key equivalancy is tested!( key_a < key_b ) && !( key_b < key_a )
bool operator< (const flavComb &a, const flavComb &b) {
    for (int i = 0; i < 5; i++) {
        if (a.flav[i] < b.flav[i])
            return true;
        if (a.flav[i] > b.flav[i])
            return false;
        
    }
    //MUST BE OUTSIDE
    return false;
}
int main () {
    FILE * In = fopen("cowpatibility.in", "r");
    long long N;
    fscanf(In, "%d", &N); 

    //set is too slow
    map <flavComb, long long> flavors;
    for (int i = 0; i < N; i++) {
        int f [5];
        fscanf(In, "%d %d %d %d %d", &f[0], &f[1], &f[2], &f[3], &f[4]);
        for (int j = 1; j <= 31; j++) {
            int comb = j;
            flavComb fC;
            int n = 0;
            for (int k = 0; k < 5; k++) {
                if ((comb&1) == 1) { 
                    fC.flav[k] = f[k];
                    n++;
                }
                
                comb = comb >> 1;
            }
           
            //cout << comb;
            sort(fC.flav, fC.flav+5);
            
           
            //cout << "\n";
            fC.n = n;  
            
            flavors[fC] += 1;
            
            //be careful with pointers
            
        }
    }

    
    long long total [5]= {0};
    for (pair <flavComb, int> p : flavors) {
        int i = p.first.n-1;
        //this has to be long long
        long long sum = p.second;
        total[i] += (sum)*(sum-1)/2;
        //cout << total[i] << "\n";
    }

   
    
    long long comp = total[0] - total[1] + total[2] - total[3] + total[4];
    //N needed to be a long
    long long uncomp = (N)*(N-1)/2 - comp;
    FILE * Out = fopen ("cowpatibility.out", "w");
    //signed long long
    fprintf(Out, "%lld\n", uncomp);
}