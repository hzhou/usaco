#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

void stat3(char a, char b, char c);

int S[26];
int D[26*26];

int main(int argc, char** argv){
    char M[9];
    FILE* In = fopen("tttt.in", "r");
    char s[10];
    fscanf(In, "%s %s %s", s, s + 3, s + 6);
    std::cout<<"s="<<s<<'\n';
    fclose(In);
    stat3(s[0], s[1], s[2]);
    stat3(s[3], s[4], s[5]);
    stat3(s[6], s[7], s[8]);
    stat3(s[0], s[3], s[6]);
    stat3(s[1], s[4], s[7]);
    stat3(s[2], s[5], s[8]);
    stat3(s[0], s[4], s[8]);
    stat3(s[2], s[4], s[6]);
    int n_S = 0;
    int n_D = 0;
    for(int  i=0; i<26; i++){
        if(S[i]){
            n_S++;
        }
    }
    for(int  i=0; i<26; i++){
        for(int  j=i+1; j<26; j++){
            if(D[i*26+j]){
                n_D++;
            }
        }
    }
    std::cout<<"n_S="<<n_S<<", "<<"n_D="<<n_D<<'\n';
    FILE* Out = fopen("tttt.out", "w");
    fprintf(Out, "%d\n", n_S);
    fprintf(Out, "%d\n", n_D);
    fclose(Out);
    return 0;
}

void stat3(char a, char b, char c){
    fprintf(stdout, "    :[stat3] a=%c, b=%c, c=%c\n", a, b, c);
    a -= 'A';
    b -= 'A';
    c -= 'A';
    if(a == b && b == c){
        S[a]++;
    }
    else if(a == b){
        D[a*26+c]++;
        D[c*26+a]++;
    }
    else if(a == c){
        D[a*26+b]++;
        D[b*26+a]++;
    }
    else if(b == c){
        D[a*26+b]++;
        D[b*26+a]++;
    }
}

