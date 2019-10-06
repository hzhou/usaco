#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int tn_cross;
    int tn_swaps_0;
    int tn_swaps_1;

    FILE* In = fopen("balance.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int *A = new int[N*2];
    for (int  i = 0; i<N*2; i++) {
        fscanf(In, " %d" ,&A[i]);
    }
    fclose(In);
    int *Z_list = new int[N*2];
    int *O_list = new int[N*2];
    int nZ0 = 0;
    int nZ1 = 0;
    for (int  i = 0; i<2*N; i++) {
        if (A[i] == 0) {
            Z_list[nZ0+nZ1] = i;
            if (i < N) {
                nZ0++;
            } else {
                nZ1++;
            }
        } else {
            O_list[i-(nZ0+nZ1)] = i;
        }
    }
    int n_Inv_0 = 0;
    int n_Inv_1 = 0;
    int tn_Z = 0;
    for (int  i = 0; i<N; i++) {
        if (A[i] == 0) {
            tn_Z++;
        } else {
            n_Inv_0 += nZ0 - tn_Z;
        }
    }
    tn_Z = 0;
    for (int  i = N; i<2*N; i++) {
        if (A[i] == 0) {
            tn_Z++;
        } else {
            n_Inv_1 += nZ1 - tn_Z;
        }
    }
    int n;
    n = n_Inv_0 - n_Inv_1;
    std::cout<<"nZ0="<<nZ0<<", "<<"nZ1="<<nZ1<<", "<<"N="<<N<<", "<<"n_Inv_0="<<n_Inv_0<<", "<<"n_Inv_1="<<n_Inv_1<<", "<<"n="<<n<<'\n';
    int count = 0;
    tn_cross = nZ0 + nZ1 - N;
    while (1) {
        if (abs(n - tn_cross) < abs(n)) {
            tn_swaps_0 = N - 1 - O_list[N-nZ0-1];
            tn_swaps_1 = Z_list[nZ0] - N;
            if (abs(n) < tn_swaps_0 + tn_swaps_1 + 1) {
                break;
            }
            if (abs(-tn_cross - tn_swaps_0 + tn_swaps_1) > tn_swaps_0 + tn_swaps_1 + 1 && abs(n) > tn_swaps_0 + tn_swaps_1 + 1 + abs(n +- tn_cross - tn_swaps_0 + tn_swaps_1)) {
                count += tn_swaps_0 + tn_swaps_1 + 1;
                n +=- tn_cross - tn_swaps_0 + tn_swaps_1;
                int tmp;
                tmp = O_list[N-nZ0-1];
                O_list[N-nZ0-1] = Z_list[nZ0];
                Z_list[nZ0] = tmp;
                nZ0++;
            } else {
                break;
            }
        } else if (abs(n + tn_cross) < abs(n)) {
            tn_swaps_0 = N - 1 - Z_list[nZ0-1];
            tn_swaps_1 = O_list[N-nZ0] - N;
            if (abs(n) < tn_swaps_0 + tn_swaps_1 + 1) {
                break;
            }
            if (abs(tn_cross + tn_swaps_0 - tn_swaps_1) > tn_swaps_0 + tn_swaps_1 + 1 && abs(n) > tn_swaps_0 + tn_swaps_1 + 1 + abs(n + tn_cross + tn_swaps_0 - tn_swaps_1)) {
                count += tn_swaps_0 + tn_swaps_1 + 1;
                n += tn_cross + tn_swaps_0 - tn_swaps_1;
                int tmp;
                tmp = O_list[N-nZ0];
                O_list[N-nZ0] = Z_list[nZ0-1];
                Z_list[nZ0-1] = tmp;
                nZ0--;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    Ans:
    count += abs(n);
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("balance.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
