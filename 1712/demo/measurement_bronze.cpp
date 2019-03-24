#include <cstdio>
#include <algorithm>

using namespace std;
int main(int argc, char** argv){
    FILE* In = fopen("measurement.in", "r");
    int N;
    fscanf(In, "%d", &N);
    int B[100], E[100], M[100];
    for(int  i=0; i<100; i++){
        B[i]=E[i]=M[i]=0;
    }
    for(int  i=0; i<N; i++){
        int day;
        char name[10];
        int change;
        fscanf(In, "%d %s %d", &day, name, &change);
        if(name[0] == 'B'){
            B[day] = change;
        }
        if(name[0] == 'E'){
            E[day] = change;
        }
        if(name[0] == 'M'){
            M[day] = change;
        }
    }
    fclose(In);
    int count = 0;
    bool is_B = true;
    bool is_E = true;
    bool is_M = true;
    B[0] = E[0] = M[0] = 7;
    for(int  i=1; i<100; i++){
        B[i] = B[i-1] + B[i];
        E[i] = E[i-1] + E[i];
        M[i] = M[i-1] + M[i];
        int n_max;
        n_max = max(max(B[i], E[i]), M[i]);
        bool is_B_tmp;
        bool is_E_tmp;
        bool is_M_tmp;
        bool need_change = false;
        is_B_tmp = (B[i] == n_max);
        if((is_B && !is_B_tmp) || (!is_B && is_B_tmp)){
            is_B = is_B_tmp;
            need_change = true;
        }
        is_E_tmp = (E[i] == n_max);
        if((is_E && !is_E_tmp) || (!is_E && is_E_tmp)){
            is_E = is_E_tmp;
            need_change = true;
        }
        is_M_tmp = (M[i] == n_max);
        if((is_M && !is_M_tmp) || (!is_M && is_M_tmp)){
            is_M = is_M_tmp;
            need_change = true;
        }
        if(need_change){
            count++;
        }
    }
    FILE* Out = fopen("measurement.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

