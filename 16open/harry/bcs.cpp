//Harry Zhou
//1hr
//Took a while to understand what the problem meant, as the wording was kinda weird
//Worked first time after debugging input (the input gave an error because I forgot to allocate a char array for each element of pieces).
#include <cstdio>
#include <algorithm>
#include <limits.h>

int N, K;
char *original;
char **pieces;

int compPieces(char *p1, char *p2);

int main() {
    FILE *fileIn = fopen("bcs.in", "r");
    FILE *fileOut = fopen("bcs.out", "w");

    fscanf(fileIn, "%d %d", &N, &K);

    original = new char[N*N+1];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%s", original + N*i);
    }

    pieces = new char*[K];
    for (int i=0; i<K; i++) {
        pieces[i] = new char[N*N+1];
    }
    for (int j=0; j<K; j++) {
        for (int i=0; i<N; i++) {
            fscanf(fileIn, "%s", &pieces[j][N*i]);
            printf("%s\n", &pieces[j][N*i]);
        }
    }

    for (int i1 = 0; i1<K-1; i1++) {
        char *p1 = pieces[i1];
        for (int i2 = i1+1; i2<K; i2++) {
            char *p2 = pieces[i2];
            if (compPieces(p1, p2)) {
                printf("%d %d\n", i1+1, i2+1);
                fprintf(fileOut, "%d %d\n", i1+1, i2+1);
                exit(0);
            }
        }
    }
}

int compPieces(char *p1, char *p2) {
    for (int x1 = -N+1; x1<=N-1; x1++) {
        for (int y1 = -N+1; y1<=N-1; y1++) {
            for (int x2 = -N+1; x2<=N-1; x2++) {
                for (int y2 = -N+1; y2<=N-1; y2++) {
                    int validCombo = 1;
                    for (int x=0; x<N; x++) {
                        for (int y=0; y<N; y++) {
                            int ix1 = x + x1;
                            int ix2 = x + x2;
                            int iy1 = y + y1;
                            int iy2 = y + y2;
                            char c1;
                            char c2;
                            if (ix1<0 || ix1>=N || iy1<0 || iy1>=N) {
                                c1 = '.';
                            }
                            else {
                                c1 = p1[iy1*N + ix1];
                            }
                            if (ix2<0 || ix2>=N || iy2<0 || iy2>=N) {
                                c2 = '.';
                            }
                            else {
                                c2 = p2[iy2*N + ix2];
                            }
                            if (c1 == '#' && c2 == '#') {
                                validCombo = 0;
                                break;
                            }
                            if (c1 == '#' || c2 == '#') {
                                if (original[y*N + x] == '#') {
                                    continue;
                                }
                                else {
                                    validCombo = 0;
                                    break;
                                }
                            }
                            else {
                                if (original[y*N + x] == '.') {
                                    continue;
                                }
                                else {
                                    validCombo = 0;
                                    break;
                                }
                            }
                        }
                        if (!validCombo) {
                            break;
                        }
                    }
                    if (validCombo) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
