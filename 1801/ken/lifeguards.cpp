//Kenneth Zhao
//25 Minutes
//Easy problem, coding was straight forward once the algorithm was found.

#include <stdio.h>

int main()
{
    FILE * In=fopen("lifeguards.in", "r");
    int N;
    fscanf(In, "%d", &N);
    int start[N+1], end[N+1];
    for(int i=0; i<N; i++)
    {
        fscanf(In, "%d %d", &start[i], &end[i]);
    }
    fclose(In);

    int time[1001];
    for(int i=0; i<1000; i++)
    {
        time[i]=0;
    }

    for(int i=0; i<N; i++)
    {
        for(int j=start[i]; j<end[i]; j++)
        {
            time[j]++;
        }
    }

    int min=1001;
    for(int i=0; i<N; i++)
    {
        int unique=0;
        for(int j=start[i]; j<end[i]; j++)
        {
            if(time[j]==1)
            {
                unique++;
            }
        }
        if(unique<min)
        {
            min=unique;
        }
    }

    int out=0;
    for(int i=0; i<1000; i++)
    {
        if(time[i]!=0)
        {
            out++;
        }
    }

    FILE * Out=fopen("lifeguards.out", "w");
    fprintf(Out, "%d\n", out-min);
    fclose(Out);
}
