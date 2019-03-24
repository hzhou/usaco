//Harry Zhou
//Timer lost, probably more than an hour
//Problems with accidentally putting commas in fscanf, std::string and c_str conversions, and edge cases
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <climits>

int main() {
    FILE *fileIn = fopen("notlast.in", "r");
    FILE *fileOut = fopen("notlast.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);
    
    std::map<std::string, int> production;
    for (int i=0; i<N; i++) {
        int amt;
        char name[10];
        fscanf(fileIn, "%s %d", name, &amt);
        std::string stdname = name;
        if (production.count(stdname) == 0) {
            production[stdname] = 0;
        }
        production[stdname] += amt;
        //printf("amt: %d\n", amt);
    }
    
    /*for (auto itr = production.begin(); itr != production.end(); itr++) {
        printf("%d\n", itr->second);
    }*/
    
    int min = production.begin()->second;
    for (auto itr = ++production.begin(); itr != production.end(); itr++) {
        if (itr->second < min) {
            min=itr->second;
        }
    }
    if (production.size() < 7) {
        min = 0;
    }

    int idealAmt = INT_MAX;
    std::string name;
    int numIdeal = 0;
    
    for (auto itr = production.begin(); itr != production.end(); itr++) {
        int amt = itr->second;
        if (amt == idealAmt) {
            numIdeal++;
            continue;
        }
        if (amt > min && amt < idealAmt) {
            idealAmt = amt;
            name = itr->first;
            numIdeal = 1;
        }
    }
    
    char answer[10];
    if (numIdeal == 1) {
        std::strcpy(answer, name.c_str());
    }
    else {
        std::strcpy(answer, "Tie");
    }
    printf("%s\n", answer);
    fprintf(fileOut, "%s\n", answer);
}
