import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * Difficulty: 3.5 / 5 - This one was hard until I found out how to do it. However, finding that out took me WAY longer
 * than I would have liked.
 *
 * Time Spent: 55 minutes
 * Input: 5 minutes
 * Creating the algorithm: 25 minutes
 * Coding: 20 minutes
 * Debugging: 5 minutes (NPE)
 *
 *
 */
public class Evolution {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("evolution.in"));
        PrintWriter out = new PrintWriter("evolution.out");
        StringTokenizer st;

        ArrayList<String> characteristics = new ArrayList<>();
        ArrayList<String>[] subpopulations = new ArrayList[25];

        int N = Integer.parseInt(buf.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(buf.readLine());
            int evols = Integer.parseInt(st.nextToken());
            subpopulations[i] = new ArrayList<String>();

            for(int j = 0; j < evols; j++){
                String cur = st.nextToken();
                subpopulations[i].add(cur);
                if(!characteristics.contains(cur)){
                    characteristics.add(cur);
                }
            }
        }

        String answer = "yes";
        for(int i = 0; i < characteristics.size(); i++){
            for(int j = i + 1; j < characteristics.size(); j++){
                if(check(i, j, N, characteristics, subpopulations)){
                    answer = "no";
                    break;
                }
            }
        }

        out.println(answer);
        out.close();
    }
    public static boolean check(int a, int b, int N, ArrayList<String> characteristics, ArrayList<String>[] subpopulations){
        boolean first = false;
        boolean second = false;
        boolean both = false;

        for(int i = 0; i < N; i++){
            boolean hasCharA = subpopulations[i].contains(characteristics.get(a));
            boolean hasCharB = subpopulations[i].contains(characteristics.get(b));

            if(hasCharA && hasCharB){ both = true; }
            else if(hasCharA){ first = true; }
            else if(hasCharB){ second = true;}
        }

        return both && first && second;
    }
}
