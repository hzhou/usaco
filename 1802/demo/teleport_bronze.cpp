#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int n_min;
    int n;

    FILE* In = fopen("teleport.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int a;
    int b;
    int x;
    int y;
    fscanf(In, " %d %d %d %d" ,&a,&b,&x,&y);
    std::cout<<"a="<<a<<", "<<"b="<<b<<", "<<"x="<<x<<", "<<"y="<<y<<'\n';
    fclose(In);
    n_min = abs(b - a);
    n = abs(x - a) + abs(b - y);
    if (n_min > n) {
        n_min = n;
    }
    n = abs(y - a) + abs(b - x);
    if (n_min > n) {
        n_min = n;
    }
    FILE* Out = fopen("teleport.out", "w");
    fprintf(Out, "%d\n", n_min);
    fclose(Out);
    return 0;
}
