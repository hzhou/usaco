
import java.io.*;
import java.util.*;

public class guess_bronze {

    public static int num_common(ArrayList<String> A, ArrayList<String> B)
    {
        int count = 0;
        for (int  i = 0; i<A.size(); i++) {
            for (int  j = 0; j<B.size(); j++) {
                if (A.get(i).equals(B.get(j))) {
                    count++;
                    break;
                }
            }
        }
        return count + 1;
    }

    public static void main(String[] args) throws IOException
    {
        int n;

        int N;
        Scanner In = new Scanner(new File("guess.in"));
        N = In.nextInt();
        ArrayList<ArrayList<String>> Animals = new ArrayList<ArrayList<String>>();
        for (int  i = 0; i<N; i++) {
            Animals.add(new ArrayList < String > ());
            String name;
            int num_attrs;
            name = In.next();
            num_attrs = In.nextInt();
            for (int  j = 0; j<num_attrs; j++) {
                name = In.next();
                Animals.get(i).add(name);
            }
        }

        int max = 0;
        for (int  i = 0; i<N; i++) {
            for (int  j = i+1; j<N; j++) {
                n = num_common(Animals.get(i), Animals.get(j));
                if (max < n) {
                    max = n;
                }
            }
        }
        PrintWriter Out = new PrintWriter(new File("guess.out"));
        Out.printf("%d\n", max);
        Out.close();
    }
}
