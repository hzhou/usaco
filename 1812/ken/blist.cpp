#include <stdio.h>
#include <vector> 

using namespace std; 
int main(){
   
	FILE * In = fopen("blist.in", "r");
	int K;
	fscanf(In, "%d", &K);
	vector<int> time;
	time.resize(1000,0);
	for(int i=0; i<K; i++){
	    int S, T, B;
	    fscanf(In, "%d %d %d", &S, &T, &B);
		for(int j=S-1; j<T; j++) {
		time[j]+=B;
		}
	}
	int max=time[0];
	for(int i=1; i<1000; i++)
	{
		if(time[i]>max)
		{
			max=time[i];
		}
	}
    fclose(In);

FILE * Out = fopen("blist.out", "w");
    fprintf(Out, "%d\n", max);
    fclose(Out);
}
