package OldCode.Bronze;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

//Old code
public class Lineup {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("lineup.in"));
        FileWriter yoink = new FileWriter("lineup.out");

        ArrayList<ArrayList<Integer>> constraints = new ArrayList<>();

        int n = Integer.parseInt(buf.readLine());
        for(int i = 0; i < n; i++){
            String[] cur = buf.readLine().split(" ");

            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(cowToInt(cur[0]));
            temp.add(cowToInt(cur[cur.length - 1]));

            constraints.add(temp);
        }

        buf.close();

        ArrayList<ArrayList<Integer>> permutations = new ArrayList<>();

        for(int a = 1; a <= 8; a++){
            for(int b = 1; b <= 8; b++){
                if(b==a) continue;
                for(int c = 1; c <= 8; c++){
                    if(c==a || c==b) continue;
                    for(int d = 1; d <= 8; d++){
                        if(d==a || d==b || d==c) continue;
                        for(int e = 1; e <= 8; e++){
                            if(e==a || e==b || e==c || e==d) continue;
                            for(int f = 1; f <= 8; f++){
                                if(f==a || f==b || f==c || f==d || f==e) continue;
                                for(int g = 1; g <= 8; g++){
                                    if(g==a || g==b || g==c || g==d || g==e || g==f) continue;
                                    for(int h = 1; h <= 8; h++){
                                        if(h==a || h==b || h==c || h==d || h==e || h==f || h==g) continue;
                                        permutations.add(new ArrayList<>(Arrays.asList(a, b, c, d, e, f, g, h)));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for(ArrayList<Integer> cur : permutations){
            boolean satisfies = true;
            for(ArrayList<Integer> constraint : constraints){
                if(Math.abs(cur.indexOf(constraint.get(0)) - cur.indexOf(constraint.get(1))) != 1){
                    satisfies = false;
                    break;
                }
            }
            if(!satisfies){
                continue;
            }
            for(int curCow : cur){
                yoink.write(intToCow(curCow));
                yoink.write("\n");
            }
            break;
        }

        yoink.close();
    }

    public static int cowToInt(String cow){
        switch(cow.trim()){
            case "Beatrice": return 1;
            case "Belinda" : return 2;
            case "Bella": return 3;
            case "Bessie": return 4;
            case "Betsy": return 5;
            case "Blue" : return 6;
            case "Buttercup" : return 7;
            case "Sue" : return 8;
            default : return -1;
        }
    }

    public static String intToCow(int cow){
        switch(cow){
            case 1 : return "Beatrice";
            case 2 : return "Belinda";
            case 3 : return "Bella";
            case 4 : return "Bessie";
            case 5 : return "Betsy";
            case 6 : return "Blue";
            case 7 : return "Buttercup";
            case 8 : return "Sue";
            default : return "";
        }
    }
}
