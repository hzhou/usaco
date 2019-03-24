//Harry Zhou
//15 min
//Took a moment to conceptualize
#include <cstdio>
#include <algorithm>

int main() {
    FILE *fileIn = fopen("highcard.in", "r");
    FILE *fileOut = fopen("highcard.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);
    
    int *elsie = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", elsie+i);
    }

    std::sort(elsie, elsie+N);
    
    int elsiePrev = elsie[0];
    int elsieNum = 1;
    for (int i=1; i<N; i++) {
        int cardsBetween = elsie[i]-elsiePrev-1;
        elsieNum = std::max( 0 , elsieNum-cardsBetween );
        elsieNum++;
        elsiePrev = elsie[i];
    }
    int cardsLeft = 2*N - elsiePrev;
    elsieNum = std::max( 0 , elsieNum-cardsLeft ); 
    
    int elsieWins = N-elsieNum;
    printf("%d\n", elsieWins);
    fprintf(fileOut, "%d\n", elsieWins);
}
