#include <stdio.h>

int main()
{
    FILE * In=fopen("paintbarn.in","r");
    int N,K;
    fscanf(In, "%d %d", &N, &K);
    int minx=1000, miny=1000, maxx=0, maxy=0;
    int barn[1000][1000];
    for(int i=0; i<N; i++)
    {
        int x1,y1,x2,y2;
        fscanf(In, "%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1<minx) minx=x1;
        if(y1<miny) miny=y1;
        if(x2>maxx) maxx=x2;
        if(y2>maxy) maxy=y2;
        for(int j=x1; j<x2; j++)
        {
            for(int k=y1; k<y2; k++)
            {
                barn[j][k]++;
            }
        }
    }
    fclose(In);


    int total=0;
    for(int i=minx; i<=maxx; i++)
    {
        for(int j=miny; j<=maxy; j++)
        {
            if(barn[i][j]==K)
            {
                total++;
            }
        }
    }


    FILE * Out=fopen("paintbarn.out", "w");
    fprintf(Out,"%d\n",total);
    fclose(Out);
}
