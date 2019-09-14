//Jasmine Zhang
//9/10/19
//10/10 cases 
//30 minutes
//Getting familiar with c++  

#include <cstdio>
//#include <algorithm> 
#include <vector> 
#include <cstdlib> 
#include <iostream>
using namespace std; 

int mamounts [3], mcapacities [3];

//methods go before main
void pour (int a, int b) {
    int m1 = mamounts[a];
    int m2 = mamounts[b];

    if (m1 + m2 <= mcapacities[b]) {
        mamounts[a] = 0;
        mamounts[b] = m1 + m2;
    }
    else {
        mamounts[a] =  m1 + m2 - mcapacities[b];
        mamounts[b] = mcapacities[b];
    }
}

int main () {
    FILE * In = fopen("mixmilk.in", "r");
    
    fscanf(In, "%d %d", &mcapacities[0], &mamounts[0]);
    fscanf(In, "%d %d", &mcapacities[1], &mamounts[1]);
    fscanf(In, "%d %d", &mcapacities[2], &mamounts[2]);
    
    for (int i = 0; i < 100; i++)
        pour(i%3, (i+1)%3);

    FILE* Out = fopen("mixmilk.out", "w");
    for (int i = 0; i < 3; i++) 
        fprintf(Out, "%d\n", mamounts[i]);
    fclose(Out);
    return 0;
}

