#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int get_id(char *name);
int get_level(int i);
char* get_rel(int i_A, int i_B, int n_diff);

char names[200][11];
int n_names = 0;
int parent_list[200];
char s_rel_buf[1000];

int main(int argc, char** argv)
{
    int i_a;
    int i_b;
    int n_A;
    int n_B;
    char *s_rel;


    for (int  i = 0; i<200; i++) {
        parent_list[i] = i;
    }

    int N;
    int i_A;
    int i_B;
    FILE* In = fopen("family.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    char A[12];
    char B[12];
    fscanf(In, "%d %s %s", &N, A, B);
    i_A = get_id(A);
    i_B = get_id(B);

    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s %s", A, B);
        i_a = get_id(A);
        i_b = get_id(B);
        parent_list[i_b] = i_a;
    }
    fclose(In);

    n_A = get_level(i_A);
    n_B = get_level(i_B);

    if (n_A <= n_B) {
        s_rel = get_rel(i_A, i_B, n_B - n_A);
    } else {
        s_rel = get_rel(i_B, i_A, n_A - n_B);
    }

    std::cout<<"s_rel="<<s_rel<<'\n';
    FILE* Out = fopen("family.out", "w");
    fprintf(Out, "%s\n", s_rel);
    fclose(Out);
    return 0;
}

int get_id(char *name)
{
    int i;

    for (int  i = 0; i<n_names; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    i = n_names;
    strcpy(names[i], name);
    n_names++;
    return i;
}

int get_level(int i)
{
    int n;

    n = 0;
    while (parent_list[i] != i) {
        i = parent_list[i];
        n++;
    }
    return n;
}

char* get_rel(int i_A, int i_B, int n_diff)
{
    char *s;
    int n;

    char *s_A = names[i_A];
    char *s_B = names[i_B];
    for (int  i = 0; i<n_diff; i++) {
        i_B = parent_list[i_B];
    }
    if (i_A == i_B) {
        if (n_diff == 1) {
            sprintf(s_rel_buf, "%s is the mother of %s", s_A, s_B);
        } else if (n_diff == 2) {
            sprintf(s_rel_buf, "%s is the grand-mother of %s", s_A, s_B);
        } else {
            s = s_rel_buf;
            n = sprintf(s, "%s is the ", s_A);
            s += n;
            for (int  i = 0; i<n_diff-2; i++) {
                n = sprintf(s, "great-");
                s += n;
            }
            sprintf(s, "grand-mother of %s", s_B);
        }
    } else if (parent_list[i_A] == parent_list[i_B]) {
        if (n_diff == 0) {
            sprintf(s_rel_buf, "SIBLINGS");
        } else if (n_diff == 1) {
            sprintf(s_rel_buf, "%s is the aunt of %s", s_A, s_B);
        } else {
            s = s_rel_buf;
            n = sprintf(s, "%s is the ", s_A);
            s += n;
            for (int  i = 0; i<n_diff-1; i++) {
                n = sprintf(s, "great-");
                s += n;
            }
            sprintf(s, "aunt of %s", s_B);
        }
    } else {
        while (parent_list[i_A] != i_A) {
            i_A = parent_list[i_A];
            i_B = parent_list[i_B];
            if (i_A == i_B) {
                break;
            }
        }
        if (i_A == i_B) {
            sprintf(s_rel_buf, "COUSINS");
        } else {
            sprintf(s_rel_buf, "NOT RELATED");
        }
    }
    return s_rel_buf;
}
