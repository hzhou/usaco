import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/*
 * Difficulty Rating: 1/5 (Incredibly easy)
 *
 * Time Spent: 17 minutes
 *
 * Time Breakdown
 * Input: 3 min
 * Creating the algorithm: 2 min
 * Coding: 10 min (mostly the if statement and making sure my cases work)
 * Debugging: 2 min
 *
 * Struggles: None (Could speed up the coding of the if statement probably,
 * there's definitely a much cleaner way to do it)
 */
public class Buckets {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("buckets.in"));
        PrintWriter out = new PrintWriter("buckets.out");

        //Java wants me to initalize these variables first...
        int barnX = -1, barnY = -1, rockX = -1, rockY = -1, lakeX = -1, lakeY = -1;

        for(int i = 0; i < 10; i++){
            String[] temp = buf.readLine().split("(?<=\\G.)"); //split by character
            for(int j = 0; j < 10; j++){
                if(temp[j].equals("B")) {
                    barnX = j;
                    barnY = i;
                }
                else if(temp[j].equals("R")){
                    rockX = j;
                    rockY = i;
                }
                else if(temp[j].equals("L")){
                    lakeX = j;
                    lakeY = i;
                }
            }
        }

        int answer = Math.abs(barnX - lakeX) + Math.abs(barnY - lakeY) - 1;
        if((lakeX == barnX && rockX == lakeX && (Math.min(barnY, lakeY) < rockY && rockY < Math.max(barnY, lakeY))) || (lakeY == barnY && rockY == lakeY && (Math.min(barnX, lakeX) < rockX && rockX < Math.max(barnX, lakeX)))){
            answer += 2;
        }
        out.println(answer);
        out.close();
    }
}
