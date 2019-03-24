#include <vector>
#include <set>
using namespace std;

using namespace std;
struct edge2 {
	int b;
	int t;
};


int main(int argc, char** argv)
{
    set<pair<int, int> > stack;
    int i;

    std::vector<struct edge2> edge2_list[N];
    for (int  i = 0; i<M; i++) {
        edge2_list[edge_list[i].a].push_back((struct edge2) {edge_list[i].b, edge_list[i].t});
        edge2_list[edge_list[i].b].push_back((struct edge2) {edge_list[i].a, edge_list[i].t});
    }
    int dist[N];
    for (int  i = 0; i<N; i++) {
        dist[i] = 1000000000;
    }
    dist[N-1] = 0;
    stack.insert(make_pair(dist[N-1], N - 1));
    while (!stack.empty()) {
        i = stack.begin()->second;
        stack.erase(stack.begin());
        for(auto e : edge2_list[i]){
            if (dist[e.b] > dist[i] + e.t && e.b < N - 1) {
                dist[e.b] = dist[i] + e.t;
                stack.insert(make_pair(dist[e.b], e.b));
            }
        }
    }
    bool has_neg = false;
    edge2_list[N-1].clear();
    for (int  i = 0; i<K; i++) {
        if (dist[hay_list[i].i] - hay_list[i].bonus < 0) {
            has_neg = true;
            break;
        }
        edge2_list[N-1].push_back((struct edge2) {hay_list[i].i, dist[hay_list[i].i] - hay_list[i].bonus});
    }
    if (has_neg) {
    } else {
        int dist2[N];
        for (int  i = 0; i<N; i++) {
            dist2[i] = 1000000000;
        }
        dist2[N-1] = 0;
        stack.insert(make_pair(dist2[N-1], N - 1));
        while (!stack.empty()) {
            i = stack.begin()->second;
            stack.erase(stack.begin());
            for(auto e : edge2_list[i]){
                if (dist2[e.b] > dist2[i] + e.t && e.b < N - 1) {
                    dist2[e.b] = dist2[i] + e.t;
                    stack.insert(make_pair(dist2[e.b], e.b));
                }
            }
        }
    }
    return 0;
}
