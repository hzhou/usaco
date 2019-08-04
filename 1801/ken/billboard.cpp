//Kenneth Zhao
//40 Minutes
//Somewhat similar to the other billboard problem, used same algorithm to find the intersection. Most time was spent on trying
//to use the macros with the functions without errors

#include <stdio.h>
#include <algorithm>
#define Lx1 x[0]
#define Lx2 x[1]
#define Fx1 x[2]
#define Fx2 x[3]
#define Ly1 y[0]
#define Ly2 y[1]
#define Fy1 y[2]
#define Fy2 y[3]

int main()
{
    FILE * In=fopen("billboard.in", "r");
    int x[4];
    int y[4];
    for(int i=0; i<4; i++)
    {
        fscanf(In, "%d %d", &x[i], &y[i]);
    }
    fclose(In);

    int xLength=Lx2-Lx1;
    int yLength=Ly2-Ly1;
    int xCommon=std::max(std::min(Lx2,Fx2)-std::max(Lx1,Fx1),0);
    int yCommon=std::max(std::min(Ly2,Fy2)-std::max(Ly1,Fy1),0);
    if(xCommon>=xLength)
    {
        if(!(Ly1<Fy1&&Ly2>Fy2)) //checks special case where food billboard is inside the lawnmower billboard
        yLength-=yCommon;
    }
    else if(yCommon>=yLength)
    {
        if(!(Lx1<Fx1&&Lx2>Fx2))
        xLength-=xCommon;
    }
    int area=xLength*yLength;

    FILE * Out=fopen("billboard.out","w");
    fprintf(Out, "%d\n", area);
    fclose(Out);
}
