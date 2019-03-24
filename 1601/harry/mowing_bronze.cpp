//Harry Zhou
//40 min
//Only error I identified and fixed was a logic error. I took the maximum of max_x instead of the minimum.
//The program passes all cases on the servers except case five.
//The server gives a runtime error. However, on my computer it runs just fine.
//Something about the way the server handles input is different from my computer, but I don't know what.
//Problem is never fixed
#include <cstdio>
#include <algorithm>
#include <map>

#define MULT 20001;

int main() {
    FILE *fileIn = fopen("mowing.in", "r");
    FILE *fileOut = fopen("mowing.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);
    
    int *dir_list = new int[N];
    char *dist_list = new char[N];
    char garbage;
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%c%c", &garbage, &garbage); //works on my computer
        //fscanf(fileIn, "%c", &garbage); //works on testing servers
        fscanf(fileIn, "%c %d", dir_list+i, dist_list+i);
        printf("%c %d\n", dir_list[i], dist_list[i]);
    }

    int max_x = -1;

    std::map<int, int> cells;
    int pos = 0;
    int t = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<dist_list[i]; j++) {
            t++;

            if (dir_list[i] == 'N') {
                pos += MULT;
            }
            else if (dir_list[i] == 'S') {
                pos -= MULT;
            }
            else if (dir_list[i] == 'E') {
                pos += 1;
            }
            else if (dir_list[i] == 'W') {
                pos -= 1;
            }

            if (cells.count(pos) && ( max_x == -1 || t-cells[pos] < max_x )) {
                printf("%d %d\n", t, cells[pos]);
                max_x = t-cells[pos];
            }
            cells[pos] = t;
        }
    }

    printf("%d\n", max_x);
    fprintf(fileOut, "%d\n", max_x);
}
