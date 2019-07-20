#include <cstdio>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct seg {
    int x1;
    int x2;
    int y1;
    int y2;
    bool is_active;
};

bool check_intersect(int i1, int i2);
int check_orientation(int x1, int y1, int x2, int y2, int x3, int y3);

struct seg *seg_list;

int main(int argc, char** argv)
{
    bool is_active;
    int xa;
    int xb;
    int i_found_a;
    int i_found_b;
    int i_seg;
    int count;
    int i_found;

    FILE* In = fopen("cowjump.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    seg_list = new struct seg[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d %d %d" ,&seg_list[i].x1,&seg_list[i].y1,&seg_list[i].x2,&seg_list[i].y2);
        is_active = false;
    }
    fclose(In);
    std::cout<<"N="<<N<<'\n';
    int P[N*2];
    for (int  i = 0; i<N*2; i++) {
        P[i] = i;
    }
    std::sort(P, P+N*2, [&](int a, int b){
        xa = a < N ? seg_list[a].x1: seg_list[a-N].x2;
        xb = b < N ? seg_list[b].x1: seg_list[b-N].x2;
        return xa < xb;
    } );
    i_found_a = -1;
    i_found_b = -1;
    std::map<int, int> Active_segs;
    for (int  i = 0; i<N*2; i++) {
        int x;
        int y;
        i_seg = P[i];
        if (i_seg >= N) {
            i_seg -= N;
        }
        x = seg_list[i_seg].x1;
        y = seg_list[i_seg].y1;
        if (!seg_list[i_seg].is_active) {
            seg_list[i_seg].is_active = true;
            auto it = Active_segs.lower_bound(y);
            if (it != Active_segs.begin()) {
                auto it_prev = it;
                it_prev--;
                if (check_intersect(it_prev->second, i_seg)) {
                    i_found_a = it_prev->second;
                    i_found_b = i_seg;
                    goto ans;
                }
            }
            if (it != Active_segs.end()) {
                auto it_next = it;
                if (check_intersect(it_next->second, i_seg)) {
                    i_found_a = it_next->second;
                    i_found_b = i_seg;
                    goto ans;
                }
            }
            Active_segs.insert(std::make_pair(y, i_seg));
        } else {
            seg_list[i_seg].is_active = false;
            auto it = Active_segs.lower_bound(y);
            auto it_prev = it;
            auto it_next = it;
            it_next++;
            if (it != Active_segs.begin()) {
                it_prev--;
                if (check_intersect(it_next->second, it_prev->second)) {
                    i_found_a = it_next->second;
                    i_found_b = it_prev->second;
                    goto ans;
                }
            }
            Active_segs.erase(it);
        }
    }
    ans:
    if (i_found_a > i_found_b) {
        int temp;
        temp = i_found_a;
        i_found_a = i_found_b;
        i_found_b = temp;
    }
    count = 0;
    for (int  i = 0; i<N; i++) {
        if (i != i_found_b && check_intersect(i, i_found_b)) {
            count++;
        }
    }
    if (count == 1) {
        i_found = i_found_a + 1;
    } else {
        i_found = i_found_b + 1;
    }
    FILE* Out = fopen("cowjump.out", "w");
    fprintf(Out, "%d\n", i_found);
    fclose(Out);
    return 0;
}

bool check_intersect(int i1, int i2)
{
    int o1 = check_orientation(seg_list[i1].x1,seg_list[i1].y1,seg_list[i1].x2,seg_list[i1].y2,seg_list[i2].x1,seg_list[i2].y1);
    int o2 = check_orientation(seg_list[i1].x1,seg_list[i1].y1,seg_list[i1].x2,seg_list[i1].y2,seg_list[i2].x2,seg_list[i2].y2);
    int o3 = check_orientation(seg_list[i2].x1,seg_list[i2].y1,seg_list[i2].x2,seg_list[i2].y2,seg_list[i1].x1,seg_list[i1].y1);
    int o4 = check_orientation(seg_list[i2].x1,seg_list[i2].y1,seg_list[i2].x2,seg_list[i2].y2,seg_list[i1].x2,seg_list[i1].y2);
    if (o1 != o2 && o3 != o4) {
        return true;
    }
    return false;
}

int check_orientation(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int ret = (y2-y1) * (x3-x1) - (y3-y1) * (x2-x1);
    if (ret < 0) {
        return -1;
    } else if (ret > 0) {
        return 1;
    } else {
        return 0;
    }
}
