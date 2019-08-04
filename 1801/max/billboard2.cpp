//Blocked Billboard
//By: Max Yang
//Time: 1 hour 10 minutes
//This problem wasn't as difficult as the other ones since it was similar to one of last week's problem.

#include <cstdio>
#include <cstdlib>
#include <stdio.h>

int main(){
    FILE * In = fopen("billboard.in", "r");

    int Ax1, Ay1, Ax2, Ay2;
    fscanf(In, "%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);

    int Bx1, By1, Bx2, By2;
    fscanf(In, "%d %d %d %d", &Bx1, &By1, &Bx2, &By2);

    fclose(In);


    int total_area = (Ax2-Ax1) * (Ay2-Ay1);
    if ((Bx2 < Ax1) && (Ay2 > By1)){
        total_area -= (Bx2-Ax1)*(Ay2-By1);
    }

    printf("%d\n", total_area);

    int ans = total_area;
    FILE * Out = fopen("billboard.out", "w");
    fprintf(Out,"%d", ans);
    fclose(Out);


}
