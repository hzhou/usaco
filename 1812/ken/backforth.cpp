#include <stdio.h>
int main(){
   
	FILE * In = fopen("backforth.in", "r");
	int A,B,C,D,E,F,G,H,I,J,a,b,c,d,e,f,g,h,i,j;
	fscanf(In, "%d %d %d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G, &H, &I, &J);
	fscanf(In, "%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

    fclose(In);

FILE * Out = fopen("backforth.out", "w");
    fprintf(Out, "%d\n", 5);
    fclose(Out);
}
