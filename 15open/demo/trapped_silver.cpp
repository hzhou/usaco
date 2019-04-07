#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct bale {
    int pos;
    int size;
};


int main(int argc, char** argv)
{
    int i1;
    int i2;
    int tn_d;

    FILE* In = fopen("trapped.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int B;
    fscanf(In, " %d %d" ,&N,&B);
    struct bale bale_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&bale_list[i].size,&bale_list[i].pos);
    }
    fclose(In);
    std::sort(bale_list, bale_list+N, [&](struct bale a, struct bale b){
        return a.pos < b.pos;
    } );
    i1 = 0;
    for (int  i = 0; i<N; i++) {
        if (bale_list[i].pos < B) {
            i1 = i;
        } else {
            break;
        }
    }
    i2 = i1 + 1;
    int min_add = 1000000000;
    for (int  i = i1; i >= 0; i--) {
        for (int  j = i2; j<N; j++) {
            int D = bale_list[j].pos-bale_list[i].pos;
            if (D <= bale_list[j].size) {
                tn_d = D - bale_list[i].size;
                if (tn_d < 0) {
                    min_add = 0;
                    break;
                } else if (min_add > tn_d) {
                    min_add = tn_d;
                    break;
                }
            }
        }
    }
    for (int  j = i2; j<N; j++) {
        for (int  i = i1; i >= 0; i--) {
            int D = bale_list[j].pos-bale_list[i].pos;
            if (D <= bale_list[i].size) {
                tn_d = D - bale_list[j].size;
                if (tn_d < 0) {
                    min_add = 0;
                    break;
                } else if (min_add > tn_d) {
                    min_add = tn_d;
                    break;
                }
            }
        }
    }
    if (min_add == 1000000000) {
        min_add = -1;
    }
    std::cout<<"min_add="<<min_add<<'\n';
    FILE* Out = fopen("trapped.out", "w");
    fprintf(Out, "%d\n", min_add);
    fclose(Out);
    return 0;
}
