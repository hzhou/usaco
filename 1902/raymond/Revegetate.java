import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * 2019-02 Bronze 02
 * Question link:
 * http://usaco.org/index.php?page=viewproblem2&cpid=916
 */
public class Revegetate {
    public static void main(String[] args) throws IOException {
        // Declare I/O
        BufferedReader buf = new BufferedReader(new FileReader("revegetate.in"));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("revegetate.out");

        //Input (using arrays based on the max size of the input), and variables representing what they are in the problem
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] a = new int[150];
        int[] b = new int[150];
        int[] grasstype = new int[100];

        for(int i = 0; i < n; i++){

        }

        /*
         * It's 2AM and I'm too tired to finish writing this. If you're reading this,
         * I'll try to finish this today, but I'm at a science competition right now,
         * so you might want to just take my Traffic and run with it. :(
         */

        //Close output
        out.close();
    }
}
