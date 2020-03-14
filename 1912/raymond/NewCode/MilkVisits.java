package NewCode;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * Difficulty rating: 4/5 (I don't know how to do trees yet)
 *
 * I figured out how to do this one (create chains made of
 * 1 type of cow, see if endpoints are on the same chain - if not,
 * check starting point of chain to see if type of milk is right),
 * but I have zero idea how to implement it. I don't know how to traverse
 * the tree of cows to create those "chains".
 *
 * Time spent: Around 30 minutes
 */
public class MilkVisits {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("meetings.in"));
        //BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("meetings.out");

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        ArrayList<String> milktype = new ArrayList<>(Arrays.asList(buf.readLine().split("(?<=\\G.)")));

        //...now what?
    }
}
