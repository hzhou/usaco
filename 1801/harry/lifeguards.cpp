//Harry Zhou
//58 min
//spend half of time figuring out proper algorithm, but it worked first try
//still using VIM
//learned how to use std::sort and structs in the process
//configured VIM to write and compile with <F4> and run with <F5>
//planning on configuring indent because default autoindent doesn't work too well
#include <cstdio>
#include <algorithm>

struct Shift {
    int start, end;
};

bool compareShifts(Shift a, Shift b) {
    return a.start<b.start;
}

int main() {
    FILE *fileIn = fopen("lifeguards.in", "r");

    int N;
    fscanf(fileIn, "%d", &N);
    Shift *shifts = new Shift[N];
    for (int i = 0; i < N; i++) {
        fscanf(fileIn, "%d %d", &shifts[i].start, &shifts[i].end);
    }

    std::sort(shifts, shifts+N, compareShifts);

    int end = 0;
    int time = 0;
    for (int i = 0; i < N-1; i++) {
        if (shifts[i].end > end) {end = shifts[i].end;}
        time += std::min(shifts[i+1].start, end) - shifts[i].start;
    }
    if (shifts[N-1].end > end) {end = shifts[N-1].end;}
    time += end - shifts[N-1].start;
    
    end = 0;
    int minDec = 1000;
    for (int i = 0; i < N-1; i++) {
        int dec = std::min(shifts[i+1].start, shifts[i].end) - std::max(shifts[i].start, end);
        dec = std::max(0, dec);
        if (dec<minDec) {minDec=dec;}
        if (shifts[i].end > end) {end = shifts[i].end;}
    }
    int dec = shifts[N-1].end - std::max(shifts[N-1].start, end);
    dec = std::max(0, dec);
    if (dec<minDec) {minDec=dec;}

    time -= minDec;

    printf("%d", time);

    FILE *fileOut = fopen("lifeguards.out", "w");
    fprintf(fileOut, "%d\n", time);

}
