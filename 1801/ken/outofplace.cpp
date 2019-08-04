//Kenneth Zhao
//20 Minutes
//Understanding the problem was the most difficult part, but once that was figured out, rest was really easy.

#include <stdio.h>
#include <algorithm>

int main()
{
    FILE * In=fopen("outofplace.in", "r");
    int N;
    fscanf(In, "%d", &N);
    int line[N+1];
    for(int i=0; i<N; i++)
    {
        fscanf(In, "%d", &line[i]);
    }
    fclose(In);


    int sortedLine[N+1];
    for(int i=0; i<N; i++)
    {
        sortedLine[i]=line[i];
    }
    std::sort(sortedLine, sortedLine+N);

    int diff=0;
    for(int i=0; i<N; i++)
    {
        if(line[i]!=sortedLine[i])
        {
            diff++;
        }
    }
    diff=std::max(diff-1,0);

    FILE * Out=fopen("outofplace.out", "w");
    fprintf(Out, "%d\n", diff);
    fclose(Out);

}
