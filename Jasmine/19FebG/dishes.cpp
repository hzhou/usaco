//Jasmine Zhang
//All cases passed
//2.5 hours

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

//array

int bSearch (int b, int e, int key, int base []);
int main () {
    FILE * In = fopen("dishes.in", "r");
    int N;
    fscanf(In, "%d", &N);

    int dishes [N];
    int base [N]; 
    for (int i = 0; i < N; i++) 
        fscanf(In, "%d", &dishes[i]);

    vector <int> stacks [N]; 
    stacks[0].push_back(dishes[0]);
    base[0] = dishes[0]; 

    int max = 0;
    int loss = 0; 
    int numStacks = 1; 
    int b = 0;
    int n = 0; 
    for (int i = 1; i < N; i++) {
        int plate = dishes[i];
        //cout << b << "-" << numStacks+b << " " << base[1] << "\n";
        int index = bSearch(b, numStacks+b-1, plate, base);
        //cout << index << " " << base[index] << " " << plate << "\n";
        
        if (max > plate) {
                n = i;
                break;
        }
        else if (index == b + numStacks) {
            numStacks++;
            stacks[index].push_back(plate);
            base[index] = plate;
        }
        
        else if (stacks[index].back() >= plate) {
            stacks[index].push_back(plate); 
        }
        
        else {
            //cout << plate << "x" << stacks[index].back() << "\n";

            numStacks -= index - b; 
            b = index; 
            //cout << b << "x" << numStacks << "\n";
            
            while (stacks[index].back() < plate) {
                //cout << plate << "j" << stacks[index].back() << "\n";
                
                max = stacks[index].back(); 
                stacks[index].pop_back();
            }
            
            
        }
        
        //cout << max << "\n";
    }   
    //cout << loss << "\n";

    FILE * Out = fopen ("dishes.out", "w");
    fprintf(Out, "%d\n", n);

    return 0;
}
int bSearch (int b, int e, int key, int arr []) {
    //cout << b << "i" << e << "\n";
    while (b <= e) {
        int m = (b+e)/2;
        int bottom = arr[m];
        if (bottom > key) 
            e = m - 1;
        else
            b = m + 1;

    }
    //cout << b << " " << e << "\n";
    return b; 
}