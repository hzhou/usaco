#include <unordered_map>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int get_cow_id(char* name);

int milk[7];
int last_id = 0;
std::unordered_map<std::string, int> M;
char cows[7][10];

int main(int argc, char** argv){
    int N;
    int P[7];
    FILE* In = fopen("notlast.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    for(int  i=0; i<7; i++){
        milk[i] = 0;
    }
    for(int  i=0; i<N; i++){
        char name[10];
        int n;
        fscanf(In, "%s %d", name, &n);
        int i_cow = get_cow_id(name);
        milk[i_cow] += n;
    }
    fclose(In);
    for(int  i=0; i<7; i++){
        P[i] = i;
    }
    std::sort(P, P+7, [](int a, int b){
        return milk[a] < milk[b];
    } );
    FILE* Out = fopen("notlast.out", "w");
    if(milk[P[6]] == milk[P[0]]){
        fprintf(Out, "Tie\n");
    }
    else{
        for(int  i=1; i<7; i++){
            if(milk[P[i]] > milk[P[i-1]]){
                if(i == 6 || milk[P[i]] < milk[P[i+1]]){
                    fprintf(Out, "%s\n", cows[P[i]]);
                }
                else{
                    fprintf(Out, "Tie\n");
                }
                break;
            }
        }
    }
    fclose(Out);
    return 0;
}

int get_cow_id(char* name){
    std::string s = name;
    if(M.count(s)){
        return M[s];
    }
    else{
        M[s] = last_id;
        strcpy(cows[last_id], name);
        last_id++;
        return M[s];
    }
}

