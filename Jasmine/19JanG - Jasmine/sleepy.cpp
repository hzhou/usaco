//Jasmine Zhang 
//15/15 cases passed
//2 hours
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int N;
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
  
void updateBIT(int BIT [], int index) 
{ 
    index++; 
    
    //cout << index << "\n";
    while (index <= N) 
    { 
        BIT[index] += 1; 
        index += index & (-index); 
    } 
} 

int main () {
    FILE * In = fopen("sleepy.in", "r");
    fscanf(In, "%d", &N);

    int order [N];
    for (int i = 0; i < N; i++) 
        fscanf(In, "%d", &order[i]);
    
    FILE * Out = fopen ("sleepy.out", "w"); 
    int a = order[N-1]; 
    int s = N-1;
    for (int i = N-2; i >= -1; i--) {
        if (i == -1 || order[i] > a) {
            fprintf(Out, "%d\n", s);
            break;
        }
        s--;
        a = order[i];
    }

    int BIT [N+1];
    fill_n(BIT, N+1, 0);
    int before [N];
    fill_n(before, N, 0);
    for (int i = N-1; i >= s; i--) {
        before[i] = sumBIT(BIT, order[i]-1);
        updateBIT(BIT, order[i]-1);
        //cout << before[i] << "\n";
    }
    for (int i = 0; i < s; i++) {
        before[i] = sumBIT(BIT, order[i]-1);
        //cout << before[i] << "\n";
    }

    fill_n(BIT, N+1, 0);
    int after [N];
    fill_n(after, N, 0);
    for (int i = 0; i < s; i++) {
        after[i] = sumBIT(BIT, order[i]-1);
        updateBIT(BIT, order[i]-1);
        //cout << after[i] << "\n";
    }

    
    
    for (int i = 0; i < s; i++) {
        //cout << after[i] << " " << before[i] << " " << s-i << "\n";
        int tot = after[i] + before[i] + s-i-1;
        if (i == s-1) 
            fprintf(Out, "%d\n", tot);
        else
            fprintf(Out, "%d ", tot);
    }

    
}

