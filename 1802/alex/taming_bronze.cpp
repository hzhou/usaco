#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	ifstream fin ("taming.in");
        ofstream fout ("taming.out");
	
	int n;
	fin >> n;
	int a[n];
	
	int between = 0;
	int start = 0;
	int end = 0;
	int known = 1;
	int unknown = 0;	

	for(int i = 0; i < n; i++)
	{
		fin >> a[i];
	}
	a[0] = 0;
	for(int i = 1; i < n; i++)
	{
		if (a[i] == -1) {
			between ++;
		} else {
                    if (between==0){
                        if (a[i]==0){
                            known++;
                        }
                        start = a[i];
                    }
                    else{
			end = a[i];
			if (end - start - 1 > between) {
                            known=-1;
                            break;
                        }
			else if (end - start - 1 != between) {
				known ++;
				unknown += between - end;
			}
			start = end;
			between = 0;
			end = 0;
                    }
		}
		if (i == n - 1 && a[i] == -1) {
			unknown += between;
		}
	}
        if(known>=0){
            cout << known << " + " << unknown << "\n";
            fout << known << " " << known + unknown << "\n";
        }else {
            cout << start << " - " << end << " - "<<between<<"\n";
            fout <<  "-1\n";
        }
}
