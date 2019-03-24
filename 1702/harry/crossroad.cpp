//Harry Zhou
//15 min
//took a bit longer to make my code easier for myself to read
#include <cstdio>
#include <algorithm>

struct observation {
    int id;
    int pos;
};

int main() {
    FILE *fileIn = fopen("crossroad.in", "r");
    FILE *fileOut = fopen("crossroad.out", "w");
    
    int N;
    fscanf(fileIn, "%d", &N);

    observation *obsList = new observation[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", &obsList[i].id, &obsList[i].pos);
        obsList[i].id--;
    }

    int *posList = new int[10];
    for (int i=0; i<10; i++) {
        posList[i] = -1;
    }
    
    int crossings = 0;
    for (int i=0; i<N; i++) {
        int id = obsList[i].id;
        int pos = obsList[i].pos;
        int prevPos = posList[id];
        
        if (prevPos == 0 && pos == 1) {
            crossings++;
        }
        if (prevPos == 1 && pos == 0) {
            crossings++;
        }

        posList[id] = pos;
    }

    printf("%d\n", crossings);
    fprintf(fileOut, "%d\n", crossings);
}
