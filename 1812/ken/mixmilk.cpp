#include <stdio.h>
int main(){
	
    FILE * In = fopen("mixmilk.in", "r");
    int A, B, C, a, b, c;
    fscanf(In, "%d %d", &A, &a);
    fscanf(In, "%d %d", &B, &b);
    fscanf(In, "%d %d", &C, &c);
    fclose(In);

    printf("A is %d - %d, B is %d - %d, C is %d - %d\n", A, a, B, b, C, c);
    int count = 0;
    while (count < 100 ){
        if (b+a <= B){
            b += a;
            a = 0;
        }
        else {
            a = (a+b) - B ;
            b = B;
        }
        count ++;
        if(count >= 100) {
            break;
        }
        // ----------------
        if (c+b <= C){
            c += b;
            b = 0;
        }
        else {
            b = (b+c) - C ;
            c = C;
        }
        count ++;
        if(count >= 100) {
            break;
        }
        // ----------------
        if (a+c <= A){
            a += c;
            c = 0;
        }
        else {
            c = (c+a) - A ;
            a = A;
        }
        count ++;
    }

    FILE * Out = fopen("mixmilk.out", "w");
    fprintf(Out, "%d\n%d\n%d\n", a, b, c);
    fclose(Out);
}
