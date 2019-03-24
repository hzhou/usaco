#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    std::sort(cows, cows+N, [](int a, int b){
        return a < b;
    } );
    int i = 0;
    while(i < N && cows[i] < N - 1 - i){
        i++;
    }
    int cnt = N-i;
    printf("%d\n", cnt);
    return 0;
}

