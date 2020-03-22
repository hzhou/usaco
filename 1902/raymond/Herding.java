import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * 2019-02 OldCode.Bronze 01
 * Question link:
 * http://usaco.org/index.php?page=viewproblem2&cpid=915
 */
public class Herding {
    public static void main(String[] args) throws IOException {
        // Declare I/O
        BufferedReader buf = new BufferedReader(new FileReader("herding.in"));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("herding.out");

        //Input (just 3 integers)
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        //cleanest way i could think of to sort these three in Java...
        int[] sorter = {a, b, c};
        Arrays.sort(sorter);
        a = sorter[0];
        b = sorter[1];
        c = sorter[2];

        /*
         * Very simple mathematics - the minimum amount of movements is always <= 2. It is 0 if they are
         * already consecutive, 1 if A/B and B/C are two apart, and 2 anytime else.
         *
         * As for the maximum amount, it's just pivoting around a gap. Pick whichever gap on a side
         * is the largest, and then just count that.
         *
         * The programming for this problem was extraordinarily trivial. It was just figuring out what to do.
         * Runs in O(1) time.
         */

        //consecutive
        if(a + 2 == c){ out.println(0); }
        //a/b or b/c two apart
        else if(a + 2 == b || b + 2 == c) { out.println(1); }
        else { out.println(2); }

        //larger gap of the two (it will be that number - 1 - found by using an example trivial case and counting)
        out.println(Math.max(b - a, c - b) - 1);


        //Close output
        out.close();
    }
}
