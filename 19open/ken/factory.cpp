//Kenneth Zhao

#include <stdio.h>

int main()
{
    FILE * In=fopen("factory.in", "r");
    int N;
    fscanf(In, "%d", &N);
    int start[N-1], end[N-1];
    for(int i=0; i<N-1; i++)
    {
        fscanf(In, "%d %d", &start[i], &end[i]);
        start[i]--;
        end[i]--;
    }
    fclose(In);

    int stations[N];
    for(int i=0; i<N; i++) //fill with 0
    {
        stations[i]=0;
    }
    for(int i=0; i<N-1; i++) //count the number of starting points each station serves
    {
        stations[start[i]]++;
    }
    int out;
    for(int i=0; i<N; i++)
    {
        if(stations[i]==0)//if it is valid, there should only be one that doesn't serve as a starting point
        {
            out=i+1;
        }
        if(stations[i]==2)//if one serves as two, then there is no valid solution
        {
            out=-1;
            break;
        }
    }

    FILE * Out=fopen("factory.out", "w");
    fprintf(Out, "%d", out);
    fclose(Out);

}
