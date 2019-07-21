//Kenneth Zhao

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * In = fopen("buckets.in", "r");
    char farm[10][10];
    for(int i=0; i<10; i++)
    {
        fscanf(In, "%s", &farm[i]);
    }
    fclose(In);

    int barnX, barnY, rockX, rockY, lakeX, lakeY;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(farm[i][j]=='B')
            {
                barnX=i,barnY=j;
            }
            if(farm[i][j]=='R')
            {
                rockX=i,rockY=j;
            }
            if(farm[i][j]=='L')
            {
                lakeX=i,lakeY=j;
            }
        }
    }
    int diffX=abs(lakeX-barnX);
    int diffY=abs(lakeY-barnY);
    int cows=diffX+diffY-1;
    if(barnX==lakeX&&barnX==rockX)
    {

        if((rockY<lakeY&&rockY>barnY)||(rockY>lakeY&&rockY<barnY))
        {
            cows=diffY+1;
        }
    }
    if(barnY==lakeY&&barnY==rockY)
    {
        if((rockX<lakeX&&rockX>barnX)||(rockX>lakeX&&rockX<barnX))
        {
            cows=diffX+1;
        }
    }

    FILE * Out=fopen("buckets.out", "w");
    fprintf(Out, "%d\n", cows);
    fclose(Out);
}
