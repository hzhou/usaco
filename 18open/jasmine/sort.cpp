//Jasmine Zhang
//2 hours
//error with lambda sorting
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int N;
bool compare(int i1, int i2);
int sumBIT(int BIT [], int index);
void updateBIT(int BIT [], int index, int val);
//int nums [];
int main () {
    FILE * In = fopen("sort.in", "r");
    
    fscanf(In, "%d", &N);

    int nums [N];
    int p [N];
    int BIT [N];
    for (int i = 0; i < N; i++) {
        fscanf(In, "%d", &nums[i]);
        p[i] = i;
    }

    //Error: expected expression
    //weird lambda parameters, what does [&] mean ??
    std::sort(p, p+N, [&](int i1, int i2)
    { 
        return (nums[i1] < nums[i2]); 
    });

    for (int i = 0; i < N; i++) 
        cout << p[i] << "\n";

    //int middle = (N-1)/2;
    //int valMiddle = nums[p[middle]];

    for (int i = 0; i < N; i++) {
        if (i < p[i]) {
            updateBIT(BIT, i+1, 1);
            if (p[i] != N-1)
                updateBIT(BIT, p[i]+1, -1);
        } 
    }

    int max = 0;
    for (int i = 1; i < N; i++) {
        int s = sumBIT(BIT, i);
        if (s > max)
            max = s;
        cout << s << "\n";
    }
    cout << max << "\n";

    FILE * Out = fopen ("sort.out", "w");
    return 0;
}

int sumBIT(int BIT [], int index) 
{   
    int sum = 0; 
    index = index + 1; 
    while (index>0) 
    { 
        sum += BIT[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void updateBIT(int BIT [], int index, int val) 
{ 
    index++; 
    while (index <= N) 
    { 
        BIT[index] += val; 
        index += index & (-index); 
    } 
} 