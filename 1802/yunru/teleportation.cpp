#include <stdio.h>
//Yunru Wang, teleportation 
int main(){ 

int t_min;
int t
	FILE* In = fopen("teleport.in", "r");
	int x;
	int y;
	int a;
	int b;
	fscanf(In,"%d", &x);
	fscanf(In,"%d", &y);
	fscanf(In,"%d", &a);
	fscanf(In,"%d", &b);
t_min = b - a;
t = b-y + (a-x);
if (t < min) {
	t = min;
}

FILE*Out = fopen("teleport.out", "w");
fprint(Out, "%d", min);
fclose(Out);
return 0;
}	
	
	
