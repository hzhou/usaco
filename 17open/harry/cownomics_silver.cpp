//Harry Zhou
//Accidentally got rid of timer
//had to add the uniqueSingles section to meet time requirements
#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    FILE *fileIn = fopen("cownomics.in", "r");
    FILE *fileOut = fopen("cownomics.out", "w");

    int N;
    int M;
    fscanf(fileIn, "%d %d", &N, &M);

    char **sCows = new char*[N];
    char **pCows = new char*[N];
    for (int i=0; i<N; i++) {
        sCows[i] = new char[M+1];
        pCows[i] = new char[M+1];
    }
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%s", sCows[i]);
    }
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%s", pCows[i]);
    }

    /*for (int i=0; i<N; i++) {
        printf("%s\n", sCows[i]);
    }
    for (int i=0; i<N; i++) {
        printf("%s\n", pCows[i]);
    }*/

    int uniqueGenes = 0;
    std::vector<int> uniqueSingles;
    for (int i1=0; i1<M; i1++) {
        int foundMatch = 0;
        for (int i_s=0; i_s<N; i_s++) {
            for (int i_p=0; i_p<N; i_p++) {
                if (sCows[i_s][i1] == pCows[i_p][i1]) { //found matching genome
                    foundMatch = 1;
                    //printf("found match at i_s: %d and i_p: %d and column: %d -- %c,%c\n", i_s, i_p, i, sCows[i_s][i], pCows[i_p][i]);
                    break;
                }
            }
            if (foundMatch) {
                break;
            }
        }
        if (!foundMatch) { //unique gene identifier
            uniqueSingles.push_back(i1);
        }
    }
    
    /*std::vector<int> uniqueDoubles1;
    std::vector<int> uniqueDoubles2;
    for (int i1=0; i1<M; i1++) {
    for (int i=0; i<uniqueSingles.size(); i++) {
        if (i1 == uniqueSingles[i]) {continue;}
    }
    for (int i2=i1+1; i2<M; i2++) {
        for (int i=0; i<uniqueSingles.size(); i++) {
            if (i1 == uniqueSingles[i]) {continue;}
        }
        int foundMatch = 0;
        for (int i_s=0; i_s<N; i_s++) {
            for (int i_p=0; i_p<N; i_p++) {
                if (sCows[i_s][i1] == pCows[i_p][i1] && sCows[i_s][i2] == pCows[i_p][i2]) { //found matching genome
                    foundMatch = 1;
                    //printf("found match at i_s: %d and i_p: %d and column: %d -- %c,%c\n", i_s, i_p, i, sCows[i_s][i], pCows[i_p][i]);
                    break;
                }
            }
            if (foundMatch) {
                break;
            }
        }
        if (!foundMatch) { //unique gene identifier
            uniqueDoubles1.push_back(i1);
            uniqueDoubles2.push_back(i2);
        }
    }
    }*/

    for (int i1=0; i1<M; i1++) {
    for (int i2=i1+1; i2<M; i2++) {
    for (int i3=i2+1; i3<M; i3++) {
        int foundMatch = 0;
        for (int i=0; i<uniqueSingles.size(); i++) {
            if (i1 == uniqueSingles[i] || i2 == uniqueSingles[i] || i3 == uniqueSingles[i]) {
                foundMatch = 1;
            }
        }
        if (foundMatch) {
            uniqueGenes++;
            continue;
        }
        for (int i_s=0; i_s<N; i_s++) {
            for (int i_p=0; i_p<N; i_p++) {
                if (sCows[i_s][i1] == pCows[i_p][i1] && sCows[i_s][i2] == pCows[i_p][i2] && sCows[i_s][i3] == pCows[i_p][i3]) { //found matching genome
                    foundMatch = 1;
                    //printf("found match at i_s: %d and i_p: %d and column: %d -- %c,%c\n", i_s, i_p, i, sCows[i_s][i], pCows[i_p][i]);
                    break;
                }
            }
            if (foundMatch) {
                break;
            }
        }
        if (!foundMatch) { //unique gene identifier
            //printf("%d\n", i);
            uniqueGenes++;
        }
    }
    }
    }

    printf("%d\n", uniqueGenes);
    fprintf(fileOut, "%d\n", uniqueGenes);

}

