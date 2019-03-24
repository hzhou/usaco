#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream fin ("homework.in");
	ofstream fout ("homework.out");

	int n;
	fin >> n;
	int nums[n];
	int sum = 0;
	vector<int> answers;
	for(int i = 0; i < n; i++)
	{
		fin >> nums[i];
		sum += nums[i];
	}
	int min;
	double maxx = 0;
	for(int k = 0; k < n - 2; k++)
	{
		sum -= nums[k];
		min = 10000;
		for(int i = k + 1; i < n; i++)
		{
			if(nums[i] < min)
			{
				min = nums[i];
			}
		}
		double temp = (double)(sum-min)/(n-k-2);
		//cout<< k<<" "<<tempsum<< " "<< min <<"\n";
		if (temp == maxx)
                {
			//cout << k << "\n";
                        answers.push_back(k);
                }
		else if (temp > maxx)
		{
			//cout << k << "\n";
			answers.clear();
			maxx = temp;
			answers.push_back(k);

			for(int i = 0; i < answers.size()+1; i++)
			{
				//cout << k << " " << answers[i] << "\n";
			}
		}
	}
	for(int i = 0; i < answers.size(); i++)
	{
		fout << answers[i] + 1 << "\n";
	}
}
