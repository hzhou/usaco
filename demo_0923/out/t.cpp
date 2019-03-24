#include <cstdio>
#include <algorithm>
struct item {
    int a;
    int b;
};
#include <map>
int main(){
    // swap, max, min
    puts("----\ntest swap max min:");
    int a = 1;
    int b = 2;
    printf(" a=%d b=%d\n", a, b);
    std::swap(a, b);
    printf(" a=%d b=%d\n", a, b);
    int c;
    c = std::max(a, b);
    printf(" c=%d\n", c);
    c = std::min(a, b);
    printf(" c=%d\n", c);
    // array
    puts("----\ntest array:");
    int A[10] = {3, 2, 1, 4, 5, 6, 9, 8, 7, 0};
    printf("A[%d] :", 10);
    for(int  i=0; i<10; i++){
        printf("%d ", A[i]);
    }
    puts("");
    std::sort(A, A+10, [](int a, int b){
        return a < b;
    } );
    printf("A[%d] :", 10);
    for(int  i=0; i<10; i++){
        printf("%d ", A[i]);
    }
    puts("");
    std::sort(A, A+10, [](int a, int b){
        return a > b;
    } );
    printf("A[%d] :", 10);
    for(int  i=0; i<10; i++){
        printf("%d ", A[i]);
    }
    puts("");
    // char array
    puts("----\ntest char array (string):");
    char s[20];
    FILE* In = fopen("t.cpp", "r");
    fscanf(In, "%s", s);
    printf("s=%s, s[1]=%c\n", s, s[1]);
    fclose(In);
    // vector
    puts("----\ntest vector:");
    std::vector<int> V;
    V.push_back(3);
    V.push_back(2);
    V.push_back(1);
    V.push_back(4);
    V.push_back(5);
    V.push_back(6);
    for(auto i: V){
        printf(" i=%d\n", i);
    }
    std::sort(V.begin(), V.end());
    printf("V[%d] :", 6);
    for(int  i=0; i<6; i++){
        printf("%d ", V[i]);
    }
    puts("");
    printf("%d\n", V[3]);
    A[3] = 100;
    printf("%d\n", V[3]);
    V[9]=10;
    printf(" V[6]=%d V[9]=%d\n", V[6], V[9]);
    // struct
    puts("----\ntest struct:");
    item A2[10];
    for(int i = 0; i<10; i++){
        A2[i] = item{i, i*2};
    }
    for(int i = 0; i<10; i++){
        printf(" A2[i].a=%d A2[i].b=%d\n", A2[i].a, A2[i].b);
    }
    std::sort(A2, A2+10, [](item a, item b){
        return a.a>b.a;
    } );
    puts("--------------------------");
    for(int i = 0; i<10; i++){
        printf(" A2[i].a=%d A2[i].b=%d\n", A2[i].a, A2[i].b);
    }
    // map
    puts("----\ntest map:");
    std::map<int,int, std::greater<int> > M;
    M[3] = 1;
    M[2] = 1;
    M[1] = 1;
    M[4] = 1;
    M[5] = 1;
    M[7] = 1;
    M[6] = 1;
    for(auto it: M){
        printf("%d\n", it.first);
    }
    return 0;
}
