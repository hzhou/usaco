//Harry Zhou
//40min
//Mixed T1 & T2 with s1 & s2
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("blocks.in", "r");

    int N;
    fscanf(fileIn, "%d", &N);
    
    int (*maxList)[26] = new int[N][26];
    for (int n=0; n<N; n++) {
        char s1[11];
        char s2[11];
        fscanf(fileIn, "%s %s", s1, s2);
        //printf("%s %s\n", s1, s2);

        int T1[26] = {0};
        int T2[26] = {0};
        for (int i=0; s1[i] != '\0'; i++) {
            T1[s1[i] - 'a']++;
        }
        for (int i=0; s2[i] != '\0'; i++) {
            T2[s2[i] - 'a']++;
        }

        for (int i=0; i<26; i++) {
            maxList[n][i] = std::max(T1[i], T2[i]);
            //printf("%d\n", maxList[n][i]);
        }
    }

    int blocks[26] = {0};
    for (int i=0; i<N; i++) {
        for (int j=0; j<26; j++) {
            blocks[j] += maxList[i][j];
        }
    }

    FILE *fileOut = fopen("blocks.out", "w");
    
    for (int i=0; i<26; i++) {
        fprintf(fileOut, "%d\n", blocks[i]);
        printf("%d\n", blocks[i]);
    }
}
