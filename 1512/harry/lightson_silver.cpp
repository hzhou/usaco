//Harry Zhou
//more than 1hr
//My first problem was that I forgot to initialize numLit
//I tried to simplify my thought process by moving more code into functions
//It did make it easier to think, but a new bug came out that took forever to figure out
//When you check pos+1, if you're at the edge it can cycle around to the other side of the grid.
//This means it doesn't catch x out of bounds if you just plug x+1 into the checking function
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

struct cell {
    int lit;
    int flag;
    std::vector<int> switches;
};

int N, M;
cell *grid;

int checkCell(int pos);

int checkVisited(int pos);

int checkTeleport(int pos);

//Debug Only
/*void printStack(std::stack<int> s) { 
    while (!s.empty()) 
    { 
        printf("\t%d", s.top());
        s.pop(); 
    } 
    printf("\n");
}*/

int main() {
    FILE *fileIn = fopen("lightson.in", "r");
    FILE *fileOut = fopen("lightson.out", "w");
    
    fscanf(fileIn, "%d %d", &N, &M);
    
    grid = new cell[N*N];
    for (int i=0; i<N*N; i++) {
        grid[i].lit = 0;
        grid[i].flag = 0;
    }
    grid[0].lit = 1;
    for (int i=0; i<M; i++) {
        int x, y, a, b;
        fscanf(fileIn, "%d %d %d %d", &x, &y, &a, &b);
        x--; y--; a--; b--;
        grid[y*N+x].switches.push_back(b*N+a);
    }

    std::stack<int> posStack;
    posStack.push(0);
    while (!posStack.empty()) {
loopStart:
        int pos = posStack.top();
        int x = pos%N;
        int y = pos/N;
        grid[pos].flag = 1;
        //printf("%d\n", pos);
        for (auto itr = grid[pos].switches.begin(); itr != grid[pos].switches.end(); itr++) {
            grid[*itr].lit = 1;
            if (checkTeleport(*itr)) {
                posStack.push(*itr);
                goto loopStart;
            }
        }
        if (x<N-1 && checkCell(pos+1)) {
            posStack.push(pos+1);
            continue;
        }
        else if (x>0 && checkCell(pos-1)) {
            posStack.push(pos-1);
            continue;
        }
        else if (y<N-1 && checkCell(pos+N)) {
            posStack.push(pos+N);
            continue;
        }
        else if (y>0 && checkCell(pos-N)) {
            posStack.push(pos-N);
            continue;
        }
        else {
            posStack.pop();
        }
    }

    int numLit = 0;
    for (int i=0; i<N*N; i++) {
        if (grid[i].lit) {
            //printf("%d %d\n", i%N+1, i/N+1);
            numLit++;
        }
    }

    printf("%d\n", numLit);
    fprintf(fileOut, "%d\n", numLit);
}

int checkCell(int pos) {
    return grid[pos].lit && !grid[pos].flag;
}

int checkVisited(int pos) {
    return grid[pos].flag;
}

int checkTeleport(int pos) {
    if (grid[pos].flag) {
        return 0;
    }
    int x = pos%N;
    int y = pos/N;
    return x<N-1 && checkVisited(pos+1) || x>0 && checkVisited(pos-1) || y<N-1 && checkVisited(pos+N) || y>0 && checkVisited(pos-N);
}
