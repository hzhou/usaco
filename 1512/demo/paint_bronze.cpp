#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int n;
    FILE* In = fopen("paint.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int a;
    int b;
    int c;
    int d;
    fscanf(In, " %d %d %d %d" ,&a,&b,&c,&d);
    std::cout<<"a="<<a<<", "<<"b="<<b<<", "<<"c="<<c<<", "<<"d="<<d<<'\n';
    fclose(In);
    n = (b - a) + (d - c);
    int x;
    int y;
    int overlap;
    x = std::max(a, c);
    y = std::min(b, d);
    overlap = std::max(0, y - x);
    n -= overlap;
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("paint.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

