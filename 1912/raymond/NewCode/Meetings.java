package NewCode;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * This problem was extraordinarily hard for me.
 * Difficulty rating: 4.5/5 - I realized that the
 * cows could "pass through" each other, but I found it
 * very hard to calculate exactly when half of the cow
 * weight overall reaches a barn.
 *
 * It doesn't help that it's quite difficult to run a meaningful simulation
 * of this on paper.
 *
 * Time spent: 1.5 hours of thinking
 * (and then I gave up, because the brute force approach I tried before
 * in the actual contest and got a few cases)
 */
public class Meetings {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("meetings.in"));
        //BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("meetings.out");

        int numCows = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken()) * 2;

        for (int i = 0; i < numCows; i++) {
            st = new StringTokenizer(buf.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int position = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
        }
    }
}
