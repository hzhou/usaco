//Harry Zhou
//10 min
//Using a 1-D array as a matrix takes a bit more mental effort.
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("cowsignal.in", "r");
    FILE *fileOut = fopen("cowsignal.out", "w");
    
    int h, w, scale;
    fscanf(fileIn, "%d %d %d", &h, &w, &scale);
    char* matrix = new char[h*w+1];
    for (int i=0; i<h; i++) {
        fscanf(fileIn, "%s", matrix+(i*w));
    }
    
    for (int y=0; y<h; y++) {
        for (int i=0; i<scale; i++) {
            for (int x=0; x<w; x++) {
                for (int j=0; j<scale; j++) {
                    fprintf(fileOut, "%c", matrix[y*w+x]);
                    printf("%c", matrix[y*w+x]);
                }
            }
            fprintf(fileOut, "\n");
            printf("\n");
        }
    }
}
