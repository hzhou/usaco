#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct log_entry{
    int day;
    char which;
    int change;
};

bool cmp(log_entry A, log_entry B){
    return A.day<B.day;
}

int main(){
    FILE* In = fopen("measurement.in", "r");
    int N;
    fscanf(In, "%d", &N);
    printf("N=%d\n", N);

    vector<struct log_entry> log;
    for(int i=0;i<N;i++){
        int day, change;
        char name[20];
        fscanf(In, "%d %s %d", &day, name, &change);
        log.push_back(log_entry{day, name[0], change});
    }

    for(int i=0;i<N; i++){
        printf("day %d: %c %d\n", log[i].day, log[i].which, log[i].change);
    }
    
    sort(log.begin(), log.end(), cmp);
    for(int i=0;i<N; i++){
        printf("day %d: %c %d\n", log[i].day, log[i].which, log[i].change);
    }
}


