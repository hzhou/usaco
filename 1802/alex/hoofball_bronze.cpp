#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
        fstream fin ("hoofball.in");
        ofstream fout ("hoofball.out");
        int n;
        fin >> n;
        int places[n];
        for(int i = 0; i < n; i++)
        {
                fin >> places[i];
        }
        sort(places, places + n);//check syntax
        int cnt_in[n];
        for(int i=0;i<n;i++){
            cnt_in[i]=0;
        }
        int passto[n];
        for(int i = 0; i < n; i++)
        {
                if (i == 0) {
                      passto[i] = i+1;
                      cnt_in[i+1]++;
                } else if (i == n-1) {
                      passto[i] = i-1;
                      cnt_in[i-1]++;
                } else {
                        if ((places[i]-places[i-1])==(places[i+1]-places[i])) {
                                passto[i] = i-1;
                                cnt_in[i-1]++;
                        } else if ((places[i]-places[i-1])>(places[i+1]-places[i])) {
                                passto[i] = i+1;
                                cnt_in[i+1]++;
                        } else {
                                passto[i] = i-1;
                                cnt_in[i-1]++;
                        }
                }
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++){
            if ((cnt_in[i]==1 && cnt_in[i+1]==1) && (passto[i]==i+1 && passto[i+1]==i)){
                count++;
            }
        }

        //number of duplicates
        sort(passto, passto + n);
        for (int i = 0; i < n - 1; i++)
        {
                if (passto[i]==passto[i+1]) {
                        cout << i <<" -> "<< passto[i]<<", "<<passto[i+1]<<" == i+1\n";
                        count ++;
                }
        }
        cout << count << "\n";
        fout << count << "\n";
        fout.close();
}
