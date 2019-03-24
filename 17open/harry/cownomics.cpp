//Harry Zhou
//30 mins
//Spent a long time debugging, but it turns out I wrote int instead of char for the arrays. Also, forgot that new[row][col] doesn't work. Next time I should stick with a 1-dimensional array.
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("cownomics.in", "r");
    FILE *fileOut = fopen("cownomics.out", "w");

    int N;
    int M;
    fscanf(fileIn, "%d %d", &N, &M);

    char **sCows = new char*[N];
    char **pCows = new char*[N];
    for (char i=0; i<N; i++) {
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
    for (int i=0; i<M; i++) {
        int foundMatch = 0;
        for (int i_s=0; i_s<N; i_s++) {
            for (int i_p=0; i_p<N; i_p++) {
                if (sCows[i_s][i] == pCows[i_p][i]) { //found matching genome
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

    printf("%d\n", uniqueGenes);
    fprintf(fileOut, "%d\n", uniqueGenes);

}
