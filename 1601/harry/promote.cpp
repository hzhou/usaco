//Harry Zhou
//10 min
//Though of using loops but realized it would be easier to enumerate
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("promote.in", "r");
    FILE *fileOut = fopen("promote.out", "w");

    int start_list[4];
    int end_list[4];

    for (int i=0; i<4; i++) {
        fscanf(fileIn, "%d %d", start_list+i, end_list+i);
    }
    
    int silver_promotes = 0;
    int gold_promotes = 0;
    int platinum_promotes = 0;

    platinum_promotes += end_list[3] - start_list[3];
    gold_promotes += end_list[3] - start_list[3];
    silver_promotes += end_list[3] - start_list[3];
    gold_promotes += end_list[2] - start_list[2];
    silver_promotes += end_list[2] - start_list[2];
    silver_promotes += end_list[1] - start_list[1];

    printf("%d\n%d\n%d\n", silver_promotes, gold_promotes, platinum_promotes);
    fprintf(fileOut, "%d\n%d\n%d\n", silver_promotes, gold_promotes, platinum_promotes);
}
