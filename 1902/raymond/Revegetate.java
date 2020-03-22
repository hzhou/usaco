import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * 2019-02 OldCode.Bronze 02
 * Question link:
 * http://usaco.org/index.php?page=viewproblem2&cpid=916
 */
public class Revegetate {
    public static void main(String[] args) throws IOException {
        // Declare I/O
        BufferedReader buf = new BufferedReader(new FileReader("revegetate.in"));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("revegetate.out");

        //Input (using arrays based on the max size of the input, and variables representing what they are in the problem)
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] a = new int[151];
        int[] b = new int[151];
        int[] grasstype = new int[101];

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(buf.readLine());
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }

        /*
         * For each pasture, check all adjacent pastures (connected b/c favorites of cow)
         * and make sure they're different colors.
         * Runs in O(n m) time, which is not a concern with our constraints. Could definitely be optimized,
         * but that's definitely not necessary when your constraints are 100 and 150.
         */

        //make i 1-based because the pastures are numbered in that fashion
        for(int i = 1; i <= n; i++){
            int j;
            for(j = 1; j <= 4; j++){
                boolean works = true;
                for(int k = 0; k < a.length; k++){
                    //If this grass type works (no adjacent same grass type)... say that it works
                    //Otherwise, continue looping until we find one that does work (we are guaranteed to find one)
                    if((i == a[k] && j == grasstype[b[k]]) || (i == b[k] && j == grasstype[a[k]])){
                        works = false;
                    }
                }
                if(works) {
                    break;
                }
            }
            grasstype[i] = j;
            out.print(j);
        }

        out.println();

        //Close output
        out.close();
    }
}
