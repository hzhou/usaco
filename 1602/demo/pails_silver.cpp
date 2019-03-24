#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct T {
	int x;
	int y;
	int k;
};


int main(int argc, char** argv){
    int X;
    int Y;
    int K;
    int M;
    std::vector<T> stack;
    std::unordered_map<int, int> cache;
    int min;
    FILE* In = fopen("pails.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d %d" ,&X,&Y,&K,&M);
    fclose(In);
    min = M;
    if(cache.count((0) * 1000 + 0) == 0){
        stack.push_back(T{0, 0, 0});
        cache[(0)*1000+0] = 1;
    }
    while(stack.size() > 0){
        int x;
        int y;
        int k;
        x = stack.back().x;
        y = stack.back().y;
        k = stack.back().k;
        stack.pop_back();
        int d = abs(M-x-y);
        if(min > d){
            min = d;
        }
        if(k < K){
            if(x < X){
                if(cache.count((X) * 1000 + y) == 0){
                    stack.push_back(T{X, y, k + 1});
                    cache[(X)*1000+y] = 1;
                }
            }
            if(y < Y){
                if(cache.count((x) * 1000 + Y) == 0){
                    stack.push_back(T{x, Y, k + 1});
                    cache[(x)*1000+Y] = 1;
                }
            }
            if(x > 0){
                if(cache.count((0) * 1000 + y) == 0){
                    stack.push_back(T{0, y, k + 1});
                    cache[(0)*1000+y] = 1;
                }
            }
            if(y > 0){
                if(cache.count((x) * 1000 + 0) == 0){
                    stack.push_back(T{x, 0, k + 1});
                    cache[(x)*1000+0] = 1;
                }
            }
            if(x > 0 && y < Y){
                if(x + y < Y){
                    if(cache.count((0) * 1000 + x + y) == 0){
                        stack.push_back(T{0, x + y, k + 1});
                        cache[(0)*1000+x+y] = 1;
                    }
                }
                else{
                    if(cache.count((x + y - Y) * 1000 + Y) == 0){
                        stack.push_back(T{x + y - Y, Y, k + 1});
                        cache[(x+y-Y)*1000+Y] = 1;
                    }
                }
            }
            if(y > 0 && x < X){
                if(x + y < X){
                    if(cache.count((x + y) * 1000 + 0) == 0){
                        stack.push_back(T{x + y, 0, k + 1});
                        cache[(x+y)*1000+0] = 1;
                    }
                }
                else{
                    if(cache.count((X) * 1000 + x + y - X) == 0){
                        stack.push_back(T{X, x + y - X, k + 1});
                        cache[(X)*1000+x+y-X] = 1;
                    }
                }
            }
        }
    }
    std::cout<<"min="<<min<<'\n';
    FILE* Out = fopen("pails.out", "w");
    fprintf(Out, "%d\n", min);
    fclose(Out);
    return 0;
}

