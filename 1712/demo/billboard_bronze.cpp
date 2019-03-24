#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    FILE* In = fopen ("billboard.in", "r");
    int Ax1, Ay1, Ax2, Ay2;
    int Bx1, By1, Bx2, By2;
    int Cx1, Cy1, Cx2, Cy2;
    fscanf(In, "%d %d %d %d", &Ax1, &Ay1, &Ax2, &Ay2);
    fscanf(In, "%d %d %d %d", &Bx1, &By1, &Bx2, &By2);
    fscanf(In, "%d %d %d %d", &Cx1, &Cy1, &Cx2, &Cy2);
    fclose(In);
    // printf("%d %d %d %d\n", Ax1, Ay1, Ax2, Ay2);
    int area = (Ax2-Ax1)*(Ay2-Ay1);
    area += (Bx2-Bx1)*(By2-By1);
    //printf("%d\n", area);

    area -= max (0, min(Ax2, Cx2)-max(Ax1, Cx1))* max (0, min(Ay2, Cy2)-max(Ay1, Cy1)); 
    area -= max (0, min(Bx2, Cx2)-max(Bx1, Cx1))* max (0, min(By2, Cy2)-max(By1, Cy1)); 

    // printf("%d\n", area);
    FILE* Out = fopen("billboard.out", "w");
    fprintf(Out, "%d\n", area);
    fclose(Out);
}
