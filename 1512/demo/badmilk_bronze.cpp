#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct Drink {
	int p;
	int m;
	int t;
};

struct Sick {
	int p;
	int t;
};


int main(int argc, char** argv){
    int N;
    int M;
    int D;
    int S;
    FILE* In = fopen("badmilk.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d %d" ,&N,&M,&D,&S);
    std::cout<<"N="<<N<<", "<<"M="<<M<<", "<<"D="<<D<<", "<<"S="<<S<<'\n';
    Drink drinks[D];
    Sick sicks[S];
    for(int  i=0; i<D; i++){
        fscanf(In, " %d %d %d" ,&drinks[i].p,&drinks[i].m,&drinks[i].t);
    }
    for(int  i=0; i<S; i++){
        fscanf(In, " %d %d" ,&sicks[i].p,&sicks[i].t);
    }
    fclose(In);
    int person[N+1] = {0};
    for(int  i=0; i<S; i++){
        person[sicks[i].p] = sicks[i].t;
    }
    int milk[M+1] = {0};
    std::sort(drinks, drinks+D, [&](Drink a, Drink b){
        return a.p < b.p || (a.p == b.p && a.m < b.m);
    } );
    int last_p = 0;
    int last_m = 0;
    for(int  i=0; i<D; i++){
        int p = drinks[i].p;
        int m = drinks[i].m;
        int sick_t = person[p];
        if(sick_t > 0 && drinks[i].t < sick_t){
            if(p != last_p || m != last_m){
                milk[m]++;
                last_p = p;
                last_m = m;
            }
        }
    }
    for(int  i=1; i<M+1; i++){
        if(milk[i] == S){
            milk[i] = 101;
            break;
        }
    }
    int cnt = S;
    for(int  i=0; i<D; i++){
        int p = drinks[i].p;
        if(person[p] == 0){
            if(milk[drinks[i].m] == 101){
                person[p] = 101;
                cnt++;
            }
        }
    }
    std::cout<<"cnt="<<cnt<<'\n';
    FILE* Out = fopen("badmilk.out", "w");
    fprintf(Out, "%d\n", cnt);
    fclose(Out);
    return 0;
}

