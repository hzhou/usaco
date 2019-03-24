//Harry Zhou
//1hr+
//Spent another really long time finding a missing & sign in fscanf()
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <string>
int main() {
    FILE *fileIn = fopen("family.in", "r");
    FILE *fileOut = fopen("family.out", "w");

    int N;
    std::string cow1, cow2;
    char arr1[11], arr2[11];
    fscanf(fileIn, "%d %s %s", &N, arr1, arr2);
    cow1 = arr1;
    cow2 = arr2;
    
    std::unordered_map<std::string, std::string> relations;
    for (int i=0; i<N; i++) {
        char cow[11], mother[11];
        fscanf(fileIn, "%s %s", mother, cow);
        relations[cow] = mother;
    }

    std::vector<std::string> ancestry1; //0 means self, 1 means mother, 2 means grandmother
    std::vector<std::string> ancestry2;
    ancestry1.push_back(cow1);
    ancestry2.push_back(cow2);

    std::string tname = cow1;
    while (relations.find(tname) != relations.end()) {
        ancestry1.push_back(tname=relations[tname]);
    }
    tname = cow2;
    while (relations.find(tname) != relations.end()) {
        ancestry2.push_back(tname=relations[tname]);
    }

    std::vector<int> ca1; //index of common ancestor
    std::vector<int> ca2;
    
    for (int i=0; i<ancestry1.size(); i++) {
        for (int j=0; j<ancestry2.size(); j++) {
            if (ancestry1[i] == ancestry2[j]) {
                ca1.push_back(i);
                ca2.push_back(j);
            }
        }
    }

    if (ca1.size() == 0) {
        fprintf(fileOut, "NOT RELATED");
        exit(0);
    }
    
    int min1 = ca1[0];
    for (int i = 1; i < ca1.size(); i++) {
        if (ca1[i]<min1) {
            min1 = ca1[i];
        }
    }
    int min2= ca2[0];
    for (int i = 1; i < ca2.size(); i++) {
        if (ca2[i]<min2) {
            min2 = ca2[i];
        }
    }
    
    std::string relation;
    if (min1 == 1 && min2 == 1) {
        fprintf(fileOut, "SIBLINGS");
    }
    else if (min1 == 0) { //most recent common ancestor is themself; they are older
        if (min2 == 1) {
            fprintf(fileOut,"%s is the mother of %s", arr1, arr2);
        }
        else {
            fprintf(fileOut,"%s is the ", arr1);
            for (int i=0; i<min2-2; i++) {
                fprintf(fileOut,"great-");
            }
            fprintf(fileOut,"grand-mother of %s", arr2);
        }
    }
    else if (min2 == 0) { //most recent common ancestor is themself; they are older
        if (min1 == 1) {
            fprintf(fileOut,"%s is the mother of %s", arr2, arr1);
        }
        else {
            fprintf(fileOut,"%s is the ", arr2);
            for (int i=0; i<min1-2; i++) {
                fprintf(fileOut,"great-");
            }
            fprintf(fileOut,"grand-mother of %s", arr1);
        }
    }
    else if (min1 == 1) { //most recent common ancestor is mother; they are older
        if (min2 == 2) {
            fprintf(fileOut,"%s is the aunt of %s", arr1, arr2);
        }
        else {
            fprintf(fileOut,"%s is the ", arr1);
            for (int i=0; i<min2-2; i++) {
                fprintf(fileOut,"great-");
            }
            fprintf(fileOut,"aunt of %s", arr2);
        }
    }
    else if (min2 == 1) { //most recent common ancestor is mother; they are older
        if (min1 == 2) {
            fprintf(fileOut,"%s is the aunt of %s", arr2, arr1);
        }
        else {
            fprintf(fileOut,"%s is the ", arr2);
            for (int i=0; i<min1-2; i++) {
                fprintf(fileOut,"great-");
            }
            fprintf(fileOut,"aunt of %s", arr1);
        }
    }
    else {
        fprintf(fileOut,"COUSINS");
    }
}
