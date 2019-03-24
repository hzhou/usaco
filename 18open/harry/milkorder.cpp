//Harry Zhou
//1hr+
//Misinterpreted question, rewrote some parts of code
//I hate segfaults. Some causes: forgot & sign when doing fscanf, mixing up i and j (giving array index out of bounds)
#include <cstdio>
#include <algorithm>
struct status {
    int id;
    int preference;
    int pos;
};

int main() {
    FILE *fileIn = fopen("milkorder.in", "r");
    FILE *fileOut = fopen("milkorder.out", "w");

    int N, M, K;
    fscanf(fileIn, "%d %d %d", &N, &M, &K);
    
    status *hierarchy = new status[M];
    int inHierarchy = 0;
    for (int i=0; i<M; i++) {
        fscanf(fileIn, "%d", &hierarchy[i].id);
        //printf("%d\n", hierarchy[i].id);
        hierarchy[i].preference = 0;
        hierarchy[i].pos = 0;
        if (hierarchy[i].id == 1) {
            inHierarchy = 1;
        }
    }
    int *order = new int[N];
    for (int i=0; i<N; i++) {
        order[i] = -1;
    }
    for (int i=0; i<K; i++) {
        int cow;
        int pos;
        fscanf(fileIn, "%d %d", &cow, &pos);
        //printf("%d %d\n", cow, pos);
        pos--;
        order[pos] = cow;
        if (cow==1) {
            printf("%d\n", pos);
            fprintf(fileOut, "%d\n", pos);
            exit(0);
        }
        for (int j=0; j<M; j++) {
            if (hierarchy[j].id == cow) {
                hierarchy[j].preference = 1;
                hierarchy[j].pos = pos;
                break;
            }
        }
    }

    /*for (int i=0; i<N; i++) {
        printf("%d ",order[i]);
    }
    printf("\n");*/
    
    if (inHierarchy) {
        int pos = 0;
        for (int i=0; i<M; i++) {
            if (hierarchy[i].preference) {
                pos = hierarchy[i].pos+1;
                continue;
            }
            while (order[pos] != -1) {
                pos++;
            }
            if (hierarchy[i].id == 1) {
                printf("%d\n", pos+1);
                fprintf(fileOut, "%d\n", pos+1);
                exit(0);
            }
            order[pos] = hierarchy[i].id; //dead code
            pos++;
        }
    }
    else {
        int pos = N-1;
        for (int i=M-1; i>=0; i--) {
            if (hierarchy[i].preference) {
                pos = hierarchy[i].pos-1;
                continue;
            }
            while (order[pos] != -1) {
                pos--;
            }
            //printf("pos: %d\ncow: %d\n", pos, hierarchy[i].id);
            order[pos] = hierarchy[i].id;
            pos--;
        }
        /*for (int i=0; i<N; i++) {
            printf("%d ",order[i]);
        }
        printf("\n");*/
        for (int i=0; i<N; i++) {
            if (order[i] == -1) {
                printf("%d\n", i+1);
                fprintf(fileOut, "%d\n", i+1);
                exit(0);
            }
        }
    }
}
