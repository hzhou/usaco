//Harry Zhou
//More than 1 hour
//As you can see, I spent most of my time trying to figure out the input.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <string>
#include <fstream>
int getkey(int a, int b) {
    return std::min(a*256+b, b*256+a); //I known chars are signed by default but I don't want to deal with that
}
int main() {
    //FILE * fileIn = fopen("tttt.in", "r");

    char *board = new char[9];
    /*for (int i=0; i<9; i++) {
        fscanf(fileIn, "%c", &board[i]); //%c reads end ofline characters
    }*/

    /*for (int i=0; i<9; i++) {
        fscanf(fileIn, "%[A-Z]", &board[i]);
    }*/
    
    std::ifstream fileIn ("tttt.in");
    std::string line1;
    std::string line2;
    std::string line3;
    getline(fileIn, line1);
    getline(fileIn, line2);
    getline(fileIn, line3);

    board[0] = line1[0];
    board[1] = line1[1];
    board[2] = line1[2];
    board[3] = line2[0];
    board[4] = line2[1];
    board[5] = line2[2];
    board[6] = line3[0];
    board[7] = line3[1];
    board[8] = line3[2];

    for (int i=0; i<9; i++) {
        printf("%c\t%d\n", board[i], board[i]);
    }
    
    std::map<int, int> winners;
    
    char a;
    char b;
    char c;

    for (int i=0; i<3; i++) {
        a = board[3*i+0];
        b = board[3*i+1];
        c = board[3*i+2];
        if (a == b && a == c) {
            winners[a] = 1;
            printf("%d\n", a);
        }
        else if (a == b) {
            winners[getkey(a,c)];
        }
        else if (b == c) {
            winners[getkey(b,a)];
        }
        else if (a == c) {
            winners[getkey(a,b)];
        }
    }

    for (int i=0; i<3; i++) {
        a = board[3*0+i];
        b = board[3*1+i];
        c = board[3*2+i];
        if (a == b && a == c) {
            winners[a] = 1;
        }
        else if (a == b) {
            winners[getkey(a,c)] = 1;
        }
        else if (b == c) {
            winners[getkey(b,a)] = 1;
        }
        else if (a == c) {
            winners[getkey(a,b)] = 1;
        }
    }

    a = board[0];
    b = board[4];
    c = board[8];
    if (a == b && a == c) {
        winners[a] = 1;
    }
    else if (a == b) {
        winners[getkey(a,c)] = 1;
    }
    else if (b == c) {
        winners[getkey(b,a)] = 1;
    }
    else if (a == c) {
        winners[getkey(a,b)] = 1;
    }

    a = board[2];
    b = board[4];
    c = board[6];
    if (a == b && a == c) {
        winners[a] = 1;
    }
    else if (a == b) {
        winners[getkey(a,c)] = 1;
    }
    else if (b == c) {
        winners[getkey(b,a)] = 1;
    }
    else if (a == c) {
        winners[getkey(a,b)] = 1;
    }
    
    int singles = 0;
    int doubles = 0;
    std::map<int,int>::iterator itr;
    for (itr = winners.begin(); itr != winners.end(); itr++) {
        if (abs(itr->first) < 128) {
            singles++;
        }
        else {
            doubles++;
        }
    }

    printf("singles: %d\ndoubles: %d\n", singles, doubles);

    FILE *fileOut = fopen("tttt.out", "w");
    fprintf(fileOut, "%d\n%d\n", singles, doubles);

}
