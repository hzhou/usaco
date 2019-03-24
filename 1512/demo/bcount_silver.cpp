#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int bin_search(int * L, int n, int val);

int N;
int Q;

int main(int argc, char** argv){
    int i1;
    int i2;
    FILE* In = fopen("bcount.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&Q);
    std::cout<<"N="<<N<<", "<<"Q="<<Q<<'\n';
    int L1[N];
    int L2[N];
    int L3[N];
    int n_1 = 0;
    int n_2 = 0;
    int n_3 = 0;
    for(int  i=0; i<N; i++){
        int id;
        fscanf(In, " %d" ,&id);
        if(id == 1){
            L1[n_1++] = i + 1;
        }
        else if(id == 2){
            L2[n_2++] = i + 1;
        }
        else if(id == 3){
            L3[n_3++] = i + 1;
        }
    }
    int A[Q];
    int B[Q];
    for(int  i=0; i<Q; i++){
        fscanf(In, " %d %d" ,&A[i],&B[i]);
    }
    fclose(In);
    FILE* Out = fopen("bcount.out", "w");
    for(int  i=0; i<Q; i++){
        i1 = bin_search(L1, n_1, A[i]);
        i2 = bin_search(L1, n_1, B[i]);
        if(L1[i1] < A[i]){
            i1++;
        }
        if(L1[i2] <= B[i]){
            i2++;
        }
        if(i2 > i1){
            fprintf(Out, "%d", i2 - i1);
        }
        else{
            fprintf(Out, "%d", 0);
        }
        fprintf(Out, " ");
        i1 = bin_search(L2, n_2, A[i]);
        i2 = bin_search(L2, n_2, B[i]);
        if(L2[i1] < A[i]){
            i1++;
        }
        if(L2[i2] <= B[i]){
            i2++;
        }
        if(i2 > i1){
            fprintf(Out, "%d", i2 - i1);
        }
        else{
            fprintf(Out, "%d", 0);
        }
        fprintf(Out, " ");
        i1 = bin_search(L3, n_3, A[i]);
        i2 = bin_search(L3, n_3, B[i]);
        if(L3[i1] < A[i]){
            i1++;
        }
        if(L3[i2] <= B[i]){
            i2++;
        }
        if(i2 > i1){
            fprintf(Out, "%d", i2 - i1);
        }
        else{
            fprintf(Out, "%d", 0);
        }
        fprintf(Out, "\n");
    }
    fclose(Out);
    return 0;
}

int bin_search(int * L, int n, int val){
    int i1;
    int i2;
    int i3;
    i1 = 0;
    i2 = n - 1;
    while(i1 <= i2){
        if(L[i1] >= val){
            return i1;
        }
        if(L[i2] <= val){
            return i2;
        }
        i3 = (i1 + i2) / 2;
        if(L[i3] == val){
            return i3;
        }
        else if(L[i3] > val){
            i2 = i3 - 1;
        }
        else{
            i1 = i3 + 1;
        }
    }
    return i1;
}

