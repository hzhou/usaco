//The Bucket Brigade
//By: Max Yang
//Time: 1 hour
//In my program, the only program I couldn't find was that I couldn't transfer the characters into the array since an array kept coming
#include <cstdlib>
#include <string>
int main(){
        FILE * In = fopen("buckets.in", "r");
        int barn_x, barn_y, rock_x, rock_y, lake_x, lake_y;

        for (int i = 1; i<=10; i++){
                char k[1];
                fscanf(In, "%c", char(k[i])); //Not transferring character correctly?
                for(int j = 1; j<=10; j++){
                        if (k[j] == 'B') {
                                barn_x = i;
                                barn_y = j;
                        }
                        if (k[j] == 'R') {
                                rock_x = i;
                                rock_y = j;
                        }
                        if (k[j] == 'L') {
                                lake_x = i;
                                lake_y = i;
                        }
                }
        }

        fclose (In);
        printf("barn: (%c, %c)", barn_x, barn_y); //check coordinate

        int ans;
        if (barn_x == rock_x == lake_x){ //#1
                ans = abs((lake_y-barn_y)+(lake_x-barn_x))+2;
        }else if (barn_y == rock_y == lake_y){ //#2
                ans = abs((lake_y-barn_y)+(lake_x-barn_x))+1;
        }else{ //#3
                ans = abs((lake_y-barn_y)+(lake_x-barn_x)); }
        FILE * Out = fopen("buckets.out", "w");
        fscanf(Out, "%d", ans);
        fclose(Out);
        
        /*
#1
..........
..........
.......BC.  B at (8, 3)
.......RC.  R at (8, 4)
.......CC.
.......L..  L at (8, 5)
..........
..........
..........
..........
8-8 + 5-3 = 2 + 2 = 4
*/

/*
#2
..........
....CCC...
..BCCRCCL. B at (3, 3); R at (6, 3); L at (9, 3)
..........
..........
..........
..........
..........
..........
..........
3-3 + 9-3 = 6 + 1 = 7
*/


/*
#3
..........
..........
..B....... B at (3, 4)
..C...R... R at (7, 5)
..C.......
..CCCCCCCL L at (10, 6)
..........
..........
..........
10-3 + 6-4 = 9
*/
