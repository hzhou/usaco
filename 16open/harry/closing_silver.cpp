//Harry Zhou
//1hr
//order of precedence errors !(*itr)->flag == flagIndex ???
//I originally solved it within an hour, but it kept timing out on the last five tests.
//After a lot of work it turns out all I needed to do was replace the vectors with sets.
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <set>

struct barn {
    int on;
    std::set<barn *> paths;
    int flag;
};

int N, M;
barn *barns;

void deleteBarn(barn *b) {
    b->on = 0;
    for (auto itr = b->paths.begin(); itr != b->paths.end(); itr++) {
        (*itr)->paths.erase(b);
    }
}

int main() {
    FILE *fileIn = fopen("closing.in", "r");
    FILE *fileOut = fopen("closing.out", "w");

    fscanf(fileIn, "%d %d", &N, &M);
    
    barns = new barn[N];
    for (int i=0; i<N; i++) {
        barns[i].on = 1;
        barns[i].flag = -1;

    }
    for (int i=0; i<M; i++) {
        int b1;
        int b2;
        fscanf(fileIn, "%d %d", &b1, &b2);
        b1--;
        b2--;
        barns[b1].paths.insert(&barns[b2]);
        barns[b2].paths.insert(&barns[b1]);
    }

    int *order = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", order+i);
        order[i]--;
    }

    barn *startingBarn = &barns[order[N-1]];
    int flagIndex = 0;
    int lastState = -1;
    for (int i=0; i<N; i++) {
        if (lastState != -1 && barns[order[i-1]].paths.size() == 1) {
            if (lastState) {
                printf("YES\n");
                fprintf(fileOut, "YES\n");
            }
            else {
                printf("NO\n");
                fprintf(fileOut, "NO\n");
            }
            deleteBarn(&barns[order[i]]);
            continue;
        }
        std::stack<barn *> barnStack;
        barnStack.push(startingBarn);
backtrackStart:
        while (!barnStack.empty()) {
            //printf("stack size: %d\n", barnStack.size());
            barn *currentBarn = barnStack.top();
            currentBarn->flag = flagIndex;
            for (auto itr = currentBarn->paths.begin(); itr != currentBarn->paths.end(); itr++) {
                //printf("%d %d %d\n", (*itr)->flag, flagIndex, (*itr)->on);
                if ((*itr)->flag != flagIndex && (*itr)->on) {
                    barnStack.push(*itr);
                    goto backtrackStart;
                }
            }
            barnStack.pop();
            goto backtrackStart;
        }
        int unvisitedBarns = 0;
        for (int j=0; j<N; j++) {
            if (barns[j].flag != flagIndex && barns[j].on) {
                unvisitedBarns = 1;
                break;
            }
        }
        if (unvisitedBarns) {
            lastState = 0;
            printf("NO\n");
            fprintf(fileOut, "NO\n");
        }
        else {
            lastState= 1;
            printf("YES\n");
            fprintf(fileOut, "YES\n");
        }

        flagIndex++;
        deleteBarn(&barns[order[i]]);
    }
}
