#include <cstring>
#include <cstdio>
#include <cstdio>
#include <algorithm>

void get_count(int i, struct node *nodes);
void update_count(int i, struct node *nodes);
struct node {
    int length;
    int count;
    long long sub_total;
    long long total;
    std::vector<int> child_list;
};

int main(int argc, char** argv)
{
    FILE* In = fopen("dirtraverse.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    node nodes[N];
    for (int  i = 0; i<N; i++) {
        nodes[i].length = 0;
        nodes[i].count = 0;
        nodes[i].sub_total = 0;
        nodes[i].total = 0;
    }
    for (int  i = 0; i<N; i++) {
        char s[17];
        int m;
        fscanf(In, "%s %d", s, &m);
        nodes[i].length = strlen(s);
        if (m > 0) {
            for (int  j = 0; j<m; j++) {
                int n;
                fscanf(In, " %d" ,&n);
                nodes[i].child_list.push_back(n - 1);
            }
        }
    }
    fclose(In);
    get_count(0, nodes);
    nodes[0].total = nodes[0].sub_total;
    update_count(0, nodes);
    long long min = nodes[0].total;
    for (int  i = 1; i<N; i++) {
        if (nodes[i].child_list.size() > 0) {
            if (min > nodes[i].total) {
                min = nodes[i].total;
            }
        }
    }
    FILE* Out = fopen("dirtraverse.out", "w");
    fprintf(Out, "%lld\n", min);
    fclose(Out);
    return 0;
}

void get_count(int i, struct node *nodes)
{
    if (nodes[i].child_list.empty()) {
        nodes[i].count = 1;
        return;
    }
    for(auto j : nodes[i].child_list){
        get_count(j, nodes);
    }
    nodes[i].count = 0;
    for(auto j : nodes[i].child_list){
        nodes[i].count += nodes[j].count;
    }
    nodes[i].sub_total = 0;
    for(auto j : nodes[i].child_list){
        if (nodes[j].child_list.empty()) {
            nodes[i].sub_total += nodes[j].length;
        } else {
            nodes[i].sub_total += (nodes[j].length + 1) * nodes[j].count + nodes[j].sub_total;
        }
    }
}

void update_count(int i, struct node *nodes)
{
    int n_total_count;

    if (nodes[i].child_list.empty()) {
        return;
    }
    n_total_count = nodes[0].count;
    for(auto j : nodes[i].child_list){
        nodes[j].total = nodes[i].total - (nodes[j].length + 1) * nodes[j].count + 3 * (n_total_count - nodes[j].count);
        update_count(j, nodes);
    }
}
