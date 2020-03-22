package OldCode.Bronze;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

//Old code
public class CowGymnastics {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("gymnastics.in"));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        FileWriter yoink = new FileWriter("gymnastics.out");

        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Integer>> cows = new ArrayList<>();

        for(int i = 0; i < k; i++){
            ArrayList<Integer> temp = new ArrayList<>();
            st = new StringTokenizer(buf.readLine());
            for(int j = 0; j < n; j++){
                temp.add(Integer.parseInt(st.nextToken()));
            }

            cows.add(temp);
        }

        int counter = 0;

        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                boolean lastOrder = false; //the last order they were in (True = i to j, false = j to i)
                boolean consistent = true;
                for(int s = 0; s < k; s++){
                    ArrayList<Integer> bruh = cows.get(s);
                    if(s == 0){
                        lastOrder = bruh.indexOf(i) < bruh.indexOf(j);
                        continue;
                    }

                    if(lastOrder != bruh.indexOf(i) < bruh.indexOf(j)){
                        consistent = false;
                        break;
                    }
                }

                if(consistent){
                    counter += 1;
                }
            }
        }
        yoink.append(String.valueOf(counter));
        yoink.close();
    }
}
