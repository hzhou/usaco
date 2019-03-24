#include <vector>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int get_id(char* name);
void get_rel(string& rel, vector<int>& AA, vector<int>& BB, char* A, char* B);

unordered_map<string, int> name_set;
vector<int> mothers;

int main(int argc, char** argv){
    int i_A;
    int i_B;
    int j;
    int N;
    char A[12];
    char B[12];
    FILE* In = fopen("family.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, "%d %s %s", &N, A, B);
    std::cout<<"N="<<N<<", "<<"A="<<A<<", "<<"B="<<B<<'\n';
    i_A = get_id(A);
    i_B = get_id(B);
    std::cout<<"i_A="<<i_A<<", "<<"i_B="<<i_B<<'\n';
    for(int  i=0; i<N; i++){
        char sA[12];
        char sB[12];
        fscanf(In, "%s %s", sA, sB);
        i_A = get_id(sA);
        i_B = get_id(sB);
        mothers[i_B] = i_A;
        printf("%d -> %d\n", i_B, i_A);
    }
    fclose(In);
    vector<int> AA;
    vector<int> BB;
    j = 0;
    AA.push_back(j);
    while(mothers[j] >= 0){
        j = mothers[j];
        AA.push_back(j);
    }
    j = 1;
    BB.push_back(j);
    while(mothers[j] >= 0){
        j = mothers[j];
        BB.push_back(j);
    }
    string rel;
    if(AA.size() > BB.size()){
        get_rel(rel, BB, AA, B, A);
    }
    else{
        get_rel(rel, AA, BB, A, B);
    }
    FILE* Out = fopen("family.out", "w");
    fprintf(Out, "%s\n", rel.c_str());
    fclose(Out);
    return 0;
}

int get_id(char* name){
    string s(name);
    if(name_set.count(s) == 0){
        name_set[s] = mothers.size();
        mothers.push_back(-1);
    }
    return name_set[s];
}

void get_rel(string& rel, vector<int>& AA, vector<int>& BB, char* A, char* B){
    int n_A;
    int n_B;
    int n;
    n_A = AA.size();
    n_B = BB.size();
    n = n_B - n_A;
    std::cout<<"n_B="<<n_B<<", "<<"n_A="<<n_A<<", "<<"n="<<n<<'\n';
    rel += A;
    rel += " is the ";
    if(n == 0 && BB[1] == AA[1]){
        rel = "SIBLINGS";
    }
    else if(BB[n] == AA[0]){
        if(n == 1){
            rel += "mother of ";
        }
        else if(n == 2){
            rel += "grand-mother of ";
        }
        else{
            for(int  i=0; i<n-2; i++){
                rel += "great-";
            }
            rel += "grand-mother of ";
        }
        rel += B;
    }
    else if(n_A > 1 && BB[n+1] == AA[1]){
        if(n == 1){
            rel += "aunt of ";
        }
        else{
            for(int  i=0; i<n-1; i++){
                rel += "great-";
            }
            rel += "aunt of ";
        }
        rel += B;
    }
    else{
        rel = "NOT RELATED";
        for(int  i=2; i<n_A; i++){
            if(BB[n+i] == AA[i]){
                rel = "COUSINS";
                break;
            }
        }
    }
}

