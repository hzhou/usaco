//Harry Zhou
//15 min
//Forgot to allocate array, which makes even ctrl^C stop working
//I ended up using ctrl^Z to get the program to exit
//But that terminates vim as well
//Took a while to figure out what was going on with swap files
//I'm still not entirely sure how I ended up with four different swap files
#include <cstdio>
#include <algorithm>

struct segment {
    int l; //length
    int s; //speed
};

int main() {
    FILE *fileIn = fopen("speeding.in", "r");
    FILE *fileOut = fopen("speeding.out", "w");

    int N, M;
    fscanf(fileIn, "%d %d", &N, &M);
    
    segment *road = new segment[N];
    segment *journey = new segment[M];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", &road[i].l, &road[i].s);
    }
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", &journey[i].l, &journey[i].s);
    }
    
    int max_over = 0;
    int seg_r = 0;
    int seg_j = 0;
    while (seg_r<N && seg_j<M) {
        max_over = std::max( max_over, journey[seg_j].s - road[seg_r].s);

        int d = std::min( road[seg_r].l, journey[seg_j].l );
        road[seg_r].l -= d;
        journey[seg_j].l -= d;

        if (journey[seg_j].l == 0) {
            seg_j++;
        }
        if (road[seg_r].l == 0) {
            seg_r++;
        }
    }

    printf("%d\n", max_over);
    fprintf(fileOut, "%d\n", max_over);
}
