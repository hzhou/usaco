//Harry Zhou
//20 mins
//cows and cows and cows
#include <cstdio>
#include <algorithm>

struct path {
    int a;
    int b;
};

int intersects(path p1, path p2) {
    if (p1.a<p2.a && p2.a<p1.b && p1.b<p2.b) {
        return 1;
    }
    else if (p1.a>p2.a && p2.a>p1.b && p1.b>p2.b) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *fileIn = fopen("circlecross.in", "r");
    FILE *fileOut = fopen("circlecross.out", "w");
    
    path *paths = new path[52];
    for (int i=0; i<52; i++) {
        paths[i].a = -1;
    }

    for (int i=0; i<52; i++) {
        char c;
        fscanf(fileIn, "%c", &c);

        int index = c-'A';
        if (paths[index].a == -1) {
            paths[index].a = i;
        }
        else {
            paths[index].b = i;
            if (paths[index].a > paths[index].b) {
                std::swap(paths[index].a, paths[index].b);
            }
        }
    }
    
    int intersections = 0;
    for (int i=0; i<52; i++) {
        for (int j=0; j<52; j++) {
            if (i==j) {continue;}
            if (intersects(paths[i],paths[j])) {
                intersections++;
            }
        }
    }
    printf("%d\n", intersections);
    fprintf(fileOut, "%d\n", intersections);
}
