#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int sumBIT(int BIT [], int index);
void updateBIT(int BIT [], int index, int val);
int N;
int main () {
    FILE * In = fopen("bphoto.in", "r");
    fscanf(In, "%d", &N);

    int heights [N];
    int p [N]; 
    int place [N]; 
    for (int i = 0; i < N; i++) {
        fscanf(In, "%d", &heights[i]);
        p[i] = i;
    }
    std::sort(p, p+N, [&heights](const int &i1, const int &i2)
    { 
        return heights[i1] < heights[i2]; 
    });

    for (int i = 0; i < N; i++) {
        place[p[i]] = i;
    }
    

    int tallerL[N];
    int BIT [N+1];
    fill_n(BIT, N+1, 0);
    for (int i = 0; i < N; i++) {
        //cout << place[i] << " " << "\n";
        tallerL[i] = sumBIT(BIT, N-1-place[i]);
        updateBIT(BIT, N-1-place[i], 1);
        //for (int i = 1; i < N+1; i++) {
            //cout <<  sumBIT(BIT, i) << " ";
        //}
        //cout << "\n";
        //cout << tallerL[i] << "\n";
    }
    
    int count = 0;
    for (int i = 0; i < N; i++){
        int l = tallerL[i];
        int r = N-place[i]-tallerL[i]-1; 
        //cout << l << " " << r << "\n";
        if (l*2 < r || r*2 < l)
            count++;
    }

    FILE * Out = fopen ("bphoto.out", "w");
    fprintf(Out, "%d\n", count);
    
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