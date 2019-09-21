//Jasmine Zhang
//9/10/19
//10/10 cases 
//30 minutes
//Getting familiar with c++  #include <cstdio>
#include <cstdlib> 
#include <algorithm> //need for sort
#include <iostream> //output stream


using namespace std;

int main () {
    FILE * In = fopen("blist.in", "r");
    int N;
    fscanf(In, "%d", &N);

    int max = 0;
    int s, e, b;
    int need [1000] = {0};//sets all numbers in array to 0

    for (int i = 0; i < N; i++) {
        fscanf(In, "%d %d %d", &s, &e, &b);
        //std::cout << s << " " << e << " " << b << "\n";
        for (int i = s; i <= e; i++) {
            need[i] += b;
            //std::cout << need[i] << "\n";
        }
    }
    std::sort(need, need+1000);

    FILE * Out = fopen("blist.out", "w");
    fprintf(Out, "%d", need[999]);
    return 0; 
}