#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct store {
    int n;
    int price;
};


int main(int argc, char** argv)
{
    int N;
    int M;
    int R;
    int k;

    FILE* In = fopen("rental.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&N,&M,&R);
    int cows[N];
    store stores[M];
    int rents[R];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&cows[i]);
    }
    for (int  i = 0; i<M; i++) {
        fscanf(In, " %d %d" ,&stores[i].n,&stores[i].price);
    }
    for (int  i = 0; i<R; i++) {
        fscanf(In, " %d" ,&rents[i]);
    }
    fclose(In);
    std::sort(cows, cows+N, [&](int a, int b){
        return a < b;
    } );
    std::sort(stores, stores+M, [&](store a, store b){
        return a.price > b.price;
    } );
    std::sort(rents, rents+R, [&](int a, int b){
        return a > b;
    } );
    int total_milk = 0;
    for (int  i = 0; i<N; i++) {
        total_milk += cows[i];
    }
    std::cout<<"N="<<N<<", "<<"M="<<M<<", "<<"R="<<R<<", "<<"total_milk="<<total_milk<<'\n';
    long long total_money = 0;
    int j = 0;
    while (j < M && total_milk > 0) {
        if (total_milk > stores[j].n) {
            total_money += stores[j].n * stores[j].price;
            total_milk -= stores[j].n;
            j++;
        } else {
            stores[j].n = total_milk;
            total_money += stores[j].n * stores[j].price;
            total_milk = 0;
            j++;
            break;
        }
    }
    j--;
    k = 0;
    for (int  i = 0; i<N; i++) {
        long long money = 0;
        if (total_milk > cows[i]) {
            total_milk -= cows[i];
            cows[i] = 0;
        } else {
            cows[i] -= total_milk;
            total_milk = 0;
        }
        if (cows[i] > 0) {
            while (j >= 0) {
                if (cows[i] > stores[j].n) {
                    cows[i] -= stores[j].n;
                    money += stores[j].n * stores[j].price;
                    j--;
                } else {
                    money += cows[i] * stores[j].price;
                    stores[j].n -= cows[i];
                    break;
                }
            }
        }
        if (k < R && money < rents[k]) {
            total_money -= money;
            total_money += rents[k];
            k++;
        } else {
            break;
        }
    }
    FILE* Out = fopen("rental.out", "w");
    fprintf(Out, "%lld\n", total_money);
    fclose(Out);
    return 0;
}
