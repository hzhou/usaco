import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * Difficulty Rating: 2/5 (algorithm took some effort to come up with)
 *
 * Time Spent: 24 minutes
 *
 * Time Breakdown
 * Input: 2 minutes
 * Creating the algorithm: 10 minutes
 * Coding: 3 minutes
 * Realizing this approach sucks and starting over: 2 more minutes
 * Input: 2 minutes
 * Coding: 5 minutes
 * Debugging: 0 minutes
 *
 * Struggles: Realized my approach was terrible and futile (too brute force and hard to code) around halfway through.
 * I simultaneously came up with a much better approach. (realizing that there existed an i if and only if there was only
 * one unique node that had no outgoing paths)
 * (The approach was going to be traversing a walkway array many times for every single node... very brute force)
 */
public class Factory {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("factory.in"));
        PrintWriter out = new PrintWriter("factory.out");
        StringTokenizer st;

        int[] outward = new int[100];
        int N = Integer.parseInt(buf.readLine());

        for(int i = 0; i < N - 1; i++){
            st = new StringTokenizer(buf.readLine());
            outward[Integer.parseInt(st.nextToken()) - 1]++;
        }

        int answer = -1;
        for(int i = 0; i < N; i++){
            if(outward[i] == 0){
                if(answer == -1) {
                    //found a sink
                    answer = i + 1;
                } else {
                    //found 2 sinks, no answer
                    answer = -1;
                    break;
                }
            }
        }
        out.println(answer);
        out.close();
    }
}
