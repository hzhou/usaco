#include <stdio.h>
#include <algorithm>
#include <string.h>

struct sensor
{
    char s[5];
    int low, high;
};

int main()
{
    FILE * In = fopen("traffic.in", "r");
    int N;
    fscanf(In, "%d", &N);
    sensor miles[N];
    int minNone, maxNone;
    bool found=false;
    for(int i=0; i<N; i++)
    {
        fscanf(In, "%s %d %d", &miles[i].s, &miles[i].low, &miles[i].high);
        if(strcmp(miles[i].s,"none")==0)
        {
            if(!found)
            {
                minNone=i;
                found=true;
            }
            maxNone=i;
        }
    }
    fclose(In);


    int beforeLow=miles[maxNone].low;
    int beforeHigh=miles[maxNone].high;
    for(int i=maxNone-1; i>=0; i--)
    {
        if(strcmp(miles[i].s,"none")==0)
        {
            beforeLow=std::max(beforeLow, miles[i].low);
            beforeHigh=std::min(beforeHigh, miles[i].high);
        }
        else if(strcmp(miles[i].s,"on")==0)
        {
            beforeLow-=miles[i].high;
            beforeHigh-=miles[i].low;
            beforeLow=std::max(0,beforeLow);
        }
        else
        {
            beforeLow+=miles[i].low;
            beforeHigh+=miles[i].high;
        }
    }

    int afterLow=miles[minNone].low;
    int afterHigh=miles[minNone].high;
    for(int i=minNone+1; i<N; i++)
    {
        if(strcmp(miles[i].s,"none")==0)
        {
            afterLow=std::max(afterLow, miles[i].low);
            afterHigh=std::min(afterHigh, miles[i].high);
        }
        else if(strcmp(miles[i].s,"on")==0)
        {
            afterLow+=miles[i].low;
            afterHigh+=miles[i].high;
        }
        else
        {
            afterLow-=miles[i].high;
            afterHigh-=miles[i].low;
            afterLow=std::max(0,afterLow);
        }
    }

    FILE * Out= fopen("traffic.out", "w");
    fprintf(Out, "%d %d\n%d %d\n", beforeLow, beforeHigh, afterLow, afterHigh);
    fclose(Out);


}
