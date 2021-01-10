#include <cstdio>
#include <cstdio>
#include <cassert>
#include <algorithm>

int main(int argc, char** argv)
{
    int in_list[7];
    int n_ret;
    int A;
    int B;
    int C;

    for (int  i = 0; i<7; i++) {
        n_ret = scanf(" %d" ,&in_list[i]);
        assert(n_ret > 0);
    }

    std::sort(in_list, in_list + 7);

    A = in_list[0];
    B = in_list[1];
    C = in_list[6] - A - B;

    printf("%d %d %d\n", A, B, C);
    return 0;
}
