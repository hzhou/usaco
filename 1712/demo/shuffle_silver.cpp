#include <cstdio>
#include <algorithm>

using namespace std;
int main(int argc, char** argv){
    int N;
    FILE* In = fopen("shuffle.in", "r");
    fscanf(In, "%d", &N);
    int P[N];
    for(int  i=0; i<N; i++){
        fscanf(In, "%d", &P[i]);
        P[i]--;
    }
    fclose(In);

    // pay attention to the seq logic
    int visited[N];
    for(int  i=0; i<N; i++){
        visited[i] = 0;
    }

    int count = 0;
    int seq = 1;

    // keep min unvisited index to speedup next cycle lookup
    int j_min = 0;
    int j;
    while(1){
        if(j_min < N){
            j = j_min;
        }
        else{
            break;
        }

        // start seq for this cycle
        int start = seq;
        while(1){ // since the exit condition is a bit complex ...
            if(visited[j]){
                if(visited[j] < start){
                    // hit previous cycle
                    break;
                }
                else{
                    // a new cycle, add cycle length
                    count += seq - visited[j];
                    break;
                }
            }
            visited[j] = seq;
            // update j_min
            if(j == j_min){
                while(j_min < N && visited[j_min]){
                    j_min++;
                }
            }
            // loop increment
            j = P[j];
            seq++;
        }
    }

    FILE* Out = fopen("shuffle.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

