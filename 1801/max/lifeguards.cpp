//Lifeguards
//By: Max Yang
//Time: 1 hour and 45 minutes
/*
Figuring out the logic part took a lot of time with the different array,
and I'm not sure if I got it completely right. After testing out the code, 
the answer was off a little for the test cases. I checked with the rest of 
the code, but I wasn't where the errors were.
*/

#include <cstdio>
#include <cstdlib>

int main(){
    FILE * In = fopen("lifeguards.in", "r");

    int N;
    fscanf(In, "%d", &N);

    int A[N+1], B[N+1];
    for(int i = 0; i<N; i++){
        fscanf(In, "%d %d", &A[i], &B[i]);
    }

    int total_hours = 0;
    fclose(In);
    for(int j = 0; j<N; j++){
        total_hours += (B[j]-A[j]);
    }

    printf("%d", total_hours);

    int time_covered[1001];
    for(int k = 0; k<N; k++){
        //inputs times covered
        for(int m = A[k]; m < B[k]; m++){
            time_covered[m]++;
        }
    }

   int time_total_lapse=0;
   int max_total_lapse=0;
   for(int d=0; d<N; d++){
        for(int m = A[d]; m < B[d]; m++){
            time_covered[m]--;
            if(time_covered[m] > 0){
                //check if lapses more than 1
                time_total_lapse++;
            }
            time_covered[m]++; //reset
        }
         if(time_total_lapse>max_total_lapse){
            max_total_lapse = time_total_lapse;
        }
        time_total_lapse = 0; //reset lapsed time for this array
    }

   total_hours -= max_total_lapse;
   printf("%d\n", total_hours);

   FILE*Out = fopen("lifeguards.out", "w");
   fprintf(Out, "%d", total_hours);
   fclose(Out);
}
