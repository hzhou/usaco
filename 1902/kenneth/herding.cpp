#include <stdio.h>

int main()
{
    FILE * In = fopen("herding.in", "r");
    int s,m,l; //small, medium, large
    fscanf(In, "%d %d %d", &s, &m, &l);
    fclose(In);

    //sort s,m,l
    if(s>m) {int k=s; s=m; m=k;}
    if(m>l) {int k=m; m=l; l=k;}
    if(s>m) {int k=s; s=m; m=k;}

    //minimum
    int min;
    if(l==s+2) {min=0;}
    else if(m==s+2||l==m+2) {min=1;}
    else {min=2;}

    //maximum
    int max;
    if(l-m>m-s) {max=l-m-1;}
    else {max=m-s-1;}


    FILE * Out = fopen("herding.out", "w");
    fprintf(Out, "%d\n%d\n", min, max);
    fclose(Out);
}
