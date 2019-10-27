#include <stdio.h>
#include <stdlib.h>
//Yunru Wang, teleportation 
int main(){ 

    int t_min;
    int t;
	FILE* In = fopen("teleport.in", "r");
	int x;
	int y;
	int a;
	int b;
	fscanf(In,"%d", &a);
	fscanf(In,"%d", &b);
	fscanf(In,"%d", &x);
	fscanf(In,"%d", &y);

    t_min = abs(b - a);

    t = abs(b-y) + abs(a-x);
    if (t_min > t) {
	t_min = t;
    }

    t = abs(b-x) + abs(a-y);
    if (t_min > t) {
	t_min = t;
    }

    FILE*Out = fopen("teleport.out", "w");
    fprintf(Out, "%d\n", t_min);
    fclose(Out);
    return 0;
}	
	
	
