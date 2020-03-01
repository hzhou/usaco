import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * 2019-02 Bronze 03
 * Question link:
 * http://usaco.org/index.php?page=viewproblem2&cpid=917
 */
public class Traffic {
    public static void main(String[] args) throws IOException {
        // Declare I/O
        BufferedReader buf = new BufferedReader(new FileReader("traffic.in"));
        StringTokenizer st;
        PrintWriter out = new PrintWriter("traffic.out");

        //Input (using arrays based on the max size of the input, and variables representing what they are in the problem)
        int n = Integer.parseInt(buf.readLine());
        String[] traffic = new String[100];
        int[] a = new int[100];
        int[] b = new int[100];

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(buf.readLine());
            traffic[i] = st.nextToken();
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }

        /*
         * The simplest way to do this that I can think of is to take a very large range and narrow it.
         * For example, if the range is some arbitrarily small number to some arbitrarily large number,
         * and the "none" sensor says [10, 15], then we narrow the range to 10, 15.
         *
         * If we then have off/on, we add/subtract a/b to the correct portion of the range. (i.e. if [5, 8] went on,
         * and we're scanning for end traffic, add 5 to min and 8 to max)
         *
         * It's the same for scanning forwards.
         *
         * There are absolutely no efficiency concerns for this approach (as is usual in bronze).
         * It's a linear, one-way scan (should run in O(n) time), and N is at most 100.
         */

        //Arbitrarily small/large numbers to represent the range
        int min = -876576545;
        int max = 234825838;

        //Traverse backwards (to get traffic prior to mile 1)
        for(int i = n - 1; i >= 0; i--){
            if(traffic[i].equals("on")) {
                min -= b[i];
                //Make sure the minimum doesn't go below 0 (tricky!)
                min = Math.max(min, 0);
                max -= a[i];
            }
            else if(traffic[i].equals("off")){
                min += a[i];
                max += b[i];
            }
            else if(traffic[i].equals("none")){
                //Narrow the range (make sure to not disturb already-narrowed limits)
                min = Math.max(a[i], min);
                max = Math.min(b[i], max);
            }
        }

        out.println(min + " " + max);

        //Reset min and max
        min = -923423532;
        max = 234234895;

        //Traverse forwards (to get traffic after the entire highway)
        for(int i = 0; i < n; i++){
            if(traffic[i].equals("on")){
                min += a[i];
                max += b[i];
            }
            else if(traffic[i].equals("off")) {
                min -= b[i];
                //Make sure the minimum doesn't go below 0 again
                min = Math.max(min, 0);
                max -= a[i];
            }
            else if(traffic[i].equals("none")){
                //Narrow the range (make sure to not disturb already-narrowed limits)
                min = Math.max(a[i], min);
                max = Math.min(b[i], max);
            }
        }

        out.println(min + " " + max);

        //Close output
        out.close();
    }
}
