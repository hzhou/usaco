//Kenneth Zhao
//150 minutes
//A lot harder than the bronze version, since iterating through all the cows in array takes too long. I had to use a set
//to keep track of the cows that are working and the unique time covered by each, to find out which one to fire.

#include <stdio.h>
#include <algorithm>
#include <set>

struct shift
{
    int time;
    int index;
    int unique=0;
};

int main()
{
    FILE * In=fopen("lifeguards.in", "r");
    int N;
    fscanf(In, "%d", &N);
    shift guards[2*N+1];
    for(int i=0; i<2*N; i++)
    {
        fscanf(In, "%d", &guards[i].time);
        guards[i].index=i;
    }
    fclose(In);

    std::sort(guards, guards+2*N, [](shift& one, shift& two)
            {
        if(one.time==two.time)
            return one.index<two.index;
        return(one.time<two.time);
            });
    std::set<int> working;

    int covered=0;
    int last;
    int prevTime;
    bool unique=false;
    bool empty=true;
    for(int i=0; i<2*N; i++)
    {
        if(guards[i].index%2==0)
        {
            working.insert(guards[i].index);
        }
        else
        {
            working.erase(guards[i].index-1);
        }

        if(unique)
        {
            guards[last].unique+=guards[i].time-prevTime;
            unique=false;
        }
        if(working.size()==1)
        {
            std::set<int>::iterator it=working.begin();
            last= *it;
            prevTime=guards[i].time;
            unique=true;
        }

        if(empty)
        {
            covered-=guards[i].time;
            empty=false;
        }
        if(working.size()==0)
        {
            covered+=guards[i].time;
            empty=true;
        }
    }

    int minUnique=1000000000;
    for(int i=0; i<N; i++)
    {
        if(guards[2*i].unique<minUnique)
        {
            minUnique=guards[2*i].unique;
        }
    }

    FILE * Out=fopen("lifeguards.out", "w");
    fprintf(Out, "%d\n", covered-minUnique);
    fclose(Out);
}
