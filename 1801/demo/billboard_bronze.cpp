#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{

    int Ax1;
    int Ay1;
    int Ax2;
    int Ay2;
    int Bx1;
    int By1;
    int Bx2;
    int By2;
    int Cx1;
    int Cy1;
    int Cx2;
    int Cy2;
    FILE* In = fopen("billboard.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d %d" ,&Ax1,&Ay1,&Ax2,&Ay2);
    fscanf(In, " %d %d %d %d" ,&Bx1,&By1,&Bx2,&By2);
    fclose(In);

    int area = (Ax2-Ax1)*(Ay2-Ay1);
    if (Bx1 <= Ax1 && Bx2 >= Ax2 && (By1 <= Ay1 || By2 >= Ay2)) {
        Cy1 = max(Ay1, By1);
        Cy2 = min(Ay2, By2);
        area -= max(0, Cy2 - Cy1) * (Ax2 - Ax1);
    } else if (By1 <= Ay1 && By2 >= Ay2 && (Bx1 <= Ax1 || Bx2 >= Ax2)) {
        Cx1 = max(Ax1, Bx1);
        Cx2 = min(Ax2, Bx2);
        area -= max(0, Cx2 - Cx1) * (Ay2 - Ay1);
    }

    FILE* Out = fopen("billboard.out", "w");
    fprintf(Out, "%d\n", area);


    fclose(Out);
    return 0;
}
