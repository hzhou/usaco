#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int count;
    int j;

    FILE* In = fopen("circlecross.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int point_list[N*2];
    for (int  i = 0; i<N*2; i++) {
        fscanf(In, " %d" ,&point_list[i]);
        point_list[i]--;
    }
    fclose(In);
    count = 0;
    std::unordered_map<int,int> M;
    int C[N*2];
    for (int  i = 0; i<N*2; i++) {
        C[i] = 0;
    }
    for (int  i = 0; i<N*2; i++) {
        if (M.count(point_list[i]) == 0) {
            int sum = 0;
            j = i;
            if (j == 0) {
                sum = C[0];
            } else {
                while (j > 0) {
                    sum += C[j];
                    j -= j &- j;
                }
            }
            M[point_list[i]] = i;
            j = i;
            while (j < N * 2) {
                C[j] += 1;
                if (j == 0) {
                    j++;
                } else {
                    j += j &- j;
                }
            }
        } else {
            {
                int sum = 0;
                j = i;
                if (j == 0) {
                    sum = C[0];
                } else {
                    while (j > 0) {
                        sum += C[j];
                        j -= j &- j;
                    }
                }
                count += sum;
            }
            {
                int sum = 0;
                j = M[point_list[i]];
                if (j == 0) {
                    sum = C[0];
                } else {
                    while (j > 0) {
                        sum += C[j];
                        j -= j &- j;
                    }
                }
                count -= sum;
            }
            j = M[point_list[i]];
            while (j < N * 2) {
                C[j] +=- 1;
                if (j == 0) {
                    j++;
                } else {
                    j += j &- j;
                }
            }
            M.erase(point_list[i]);
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("circlecross.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
