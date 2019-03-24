//Harry Zhou
//30 min
//Made logic errors this time.
//First time the error was that I used i for the radius of the explosion. Instead I needed to create a separate rad variable.
//The second error was that I didn't have the right_dead and left_dead flangs.
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("angry.in", "r");
    FILE *fileOut = fopen("angry.out", "w");
    
    int N;
    fscanf(fileIn, "%d", &N);

    int *pos_list = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", pos_list+i);
    }

    std::sort(pos_list, pos_list+N);
    
    int max_bales = 0;
    for (int i=0; i<N; i++) {
        int left = i;
        int right = i;
        int t_bales = 1;
        int rad = 1;
        int right_dead = 0;
        int left_dead = 0;
        while (true) {
            int shift_left = 0;
            while (!left_dead && left-shift_left>0 && pos_list[left]-pos_list[left-shift_left-1]<=rad) {
                shift_left++;
                t_bales++;
            }
            int shift_right = 0;
            while (!right_dead && right+shift_right<N-1 && pos_list[right+shift_right+1]-pos_list[right]<=rad) {
                shift_right++;
                t_bales++;
            }
            if (shift_left == 0 && shift_right == 0) {
                break;
            }
            else if (shift_left == 0) {
                left_dead = 1;
            }
            else if (shift_right == 0) {
                right_dead = 1;
            }
            left -= shift_left;
            right += shift_right;
            rad++;
        }
        if (t_bales>max_bales) {
            max_bales = t_bales;
        }
    }

    printf("%d\n", max_bales);
    fprintf(fileOut, "%d\n", max_bales);
}
