#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    unsigned char c;
    FILE* In = fopen("circlecross.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    char L[100];
    fscanf(In, "%s", L);
    std::cout<<"L="<<L<<'\n';
    fclose(In);
    int A[26];
    int B[26];
    for(int  i=0; i<26; i++){
        A[i] = -1;
    }
    for(int  i=0; i<52; i++){
        c = L[i] - 'A';
        if(A[c] < 0){
            A[c] = i;
        }
        else{
            B[c] = i;
        }
    }
    int count = 0;
    for(int  i=0; i<26; i++){
        for(int  j=i+1; j<26; j++){
            if((A[i] < A[j] && A[j] < B[i] && B[i] < B[j]) || (A[j] < A[i] && A[i] < B[j] && B[j] < B[i])){
                count++;
            }
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("circlecross.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

