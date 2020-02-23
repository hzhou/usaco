//Jasmine Zhang
//1.5 hours
//9/10 cases passed
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int main () {
    int N;
    FILE * In = fopen("art2.in", "r");
    fscanf(In, "%d", &N);

    int painting [N+2];
    //setting up initial canvas 
    painting[0] = 0;
    painting[N+1] = 0;

    for (int i = 1; i < N+1; i++) 
        fscanf(In, "%d", &painting[i]);

    // ------------------------------------
    int beg [N+1]; //first occurance of a number
    fill_n(beg, N+1, -1);
    int end [N+1]; //second occurance of a number
    fill_n(end, N+1, -1);
    for (int i = 0; i < N+2; i++) {
        int n = painting[i];
        if (beg[n] == -1) 
            beg[n] = i; 
         end[n] = i;
    }
    /*
    for (int i = 0; i < N+1; i++) {
        cout << beg[i] << " " << end[i] << "\n";
    }
    */

    int count = 0; // current layers
    int maxLayer = 0; // maximum layers so far
    int layers [N+1]; // color of each current layers 
    
    for (int i = 0; i < N+2; i++) {
        int n = painting[i];
        //cout << n << " " << i << "\n";
        //cout << beg[n] << " " << i << "\n";
        if (i==beg[n] && i==end[n]) {
            maxLayer = max(count+1, maxLayer);
        }
        else if (i == beg[n]) {
            layers[count] = n;
            count++;
            maxLayer = max(count, maxLayer);
        }
        else if (layers[count-1] != n) {
            maxLayer = -1;
            break;
        }
        else if (i == end[n]) {
            count--;
            layers[count] = -1;
        }
        else{
        }
    }

    if (maxLayer<0) {
        maxLayer = 0;
    }
    FILE * Out = fopen ("art2.out", "w");
    fprintf(Out, "%d\n", maxLayer-1);
    return 0; 
}
