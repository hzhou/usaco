//Jasmine Zhang
//2.5 hours
//errors
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std; 


struct observation {
    int num;
    int order [];
};

bool canOrder (int index, observation obs [], int answer []);
int N, M;
int main () {
    FILE * In = fopen("milkorder.in", "r");
    
    fscanf(In, "%d %d", &N, &M);

    observation obs [N];
    for (int i = 0; i < M; i++) {
        fscanf(In, "%d", &obs[i].num);
        obs[i].order [obs[i].num];
        for (int j = 0; j < obs[i].num; j++) {
            fscanf(In, "%d", &obs[i].order[j]);
            cout << obs[i].order[j] << " ";
        }
        cout << "\n";
    }
    
    int b = 0;
    int e = N-1;
    int answer [N];
    while (b < e) {
        int m = (b+e)/2;
        if (canOrder(m, obs, answer)) 
            b = m + 1;
        else
            e = m - 1;
    }

    FILE * Out = fopen("milkorder.out", "w");
    for (int i = 0; i < N; i++) {
        if (i != N-1)
            fprinf("%d ", &answer[i]);
        else
            fprinf("%d\n", &answer[i]);
    }

    return 0;
}

bool canOrder (int index, observation obs [], int answer []) {
    int pred [N];
    fill_n(pred, N, 0);
    vector <int> hierarchy [N];
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < obs[i].num-1; j++) {
            int first = obs[i].order[j];
            int second = obs[i].order[j];
            hierarchy[first].push_back(second);
            pred[second]++;
        } 
    }
    
    priority_queue <int, vector<int>, greater<int> > pq; 
    //only add to graph is no cow has to go before
    for (int i = 0; i < N; i++) {
			if (pred[i] == 0)
				pq.push(i);
	}
	for (int i = 0; i < N; i++) {
		//if the graph is cyclic, then the cyclic numbers never gets added on 
		//because they need the other number to be added on first
		if (pq.empty())
			return false;
		int v = pq.top();
        pq.pop(); 

		answer[i] = v;
			
		for (int succ : hierarchy[v]) {
			pred[succ]--;
				if (pred[succ] == 0) {
					pq.push(succ);
				}
			}
			
		}


    return true;
}