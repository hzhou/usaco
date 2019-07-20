#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    bool is_all_one;

    FILE* In = fopen("leftout.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    char grid[N*N+1];
    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s", &grid[i*N]);
    }
    fclose(In);
    for (int  i = 0; i<N*N; i++) {
        if (grid[i] == 'L') {
            grid[i] = 0;
        } else {
            grid[i] = 1;
        }
    }
    for (int  j = 0; j<N; j++) {
        if (grid[j] == 1) {
            for (int  i = 0; i<N; i++) {
                grid[i*N+j] = 1 - grid[i*N+j];
            }
        }
    }
    for (int  i = 0; i<N; i++) {
        if (grid[i*N] == 1) {
            for (int  j = 0; j<N; j++) {
                grid[i*N+j] = 1 - grid[i*N+j];
            }
        }
    }
    int i_bad = -1;
    int j_bad = -1;
    is_all_one = true;
    for (int  i = 1; i<N; i++) {
        for (int  j = 1; j<N; j++) {
            if (grid[i*N+j] != 1) {
                is_all_one = false;
                goto check_all_one;
            }
        }
    }
    check_all_one:
    if (is_all_one) {
        i_bad = 0;
        j_bad = 0;
        goto all_done;
    }
    for (int  i = 1; i<N; i++) {
        is_all_one = true;
        for (int  j = 1; j<N; j++) {
            if (grid[i*N+j] != 1) {
                is_all_one = false;
                break;
            }
        }
        if (is_all_one) {
            if (i_bad == -1) {
                i_bad = i;
                j_bad = 0;
            } else {
                i_bad = -1;
                goto all_done;
            }
        }
    }
    if (i_bad >= 0) {
        goto all_done;
    }
    for (int  i = 1; i<N; i++) {
        for (int  j = 1; j<N; j++) {
            if (grid[i*N+j] == 1) {
                if (i_bad == -1) {
                    i_bad = i;
                    j_bad = j;
                } else {
                    i_bad = -1;
                    goto all_done;
                }
            }
        }
    }
    all_done:
    std::cout<<"N="<<N<<", "<<"i_bad="<<i_bad<<", "<<"j_bad="<<j_bad<<'\n';
    FILE* Out = fopen("leftout.out", "w");
    if (i_bad < 0) {
        fprintf(Out, "-1\n");
    } else {
        i_bad++;
        j_bad++;
        fprintf(Out, "%d %d\n", i_bad, j_bad);
    }
    fclose(Out);
    return 0;
}
