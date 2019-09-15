
import java.io.*;
import java.util.*;

public class blist_bronze {

    public static void main(String[] args) throws IOException
    {
        int N;
        Scanner In = new Scanner(new File("blist.in"));
        N = In.nextInt();
        int[] S = new int[N];
        int[] T = new int[N];
        int[] B = new int[N];
        for (int  i = 0; i<N; i++) {
            S[i] = In.nextInt();
            T[i] = In.nextInt();
            B[i] = In.nextInt();
        }
        int[] time_slots = new int[1000];
        for (int  i = 0; i<N; i++) {
            for (int  j = S[i]; j<T[i]; j++) {
                time_slots[j] += B[i];
            }
        }
        int max = 0;
        for (int  i = 0; i<1000; i++) {
            if (max < time_slots[i]) {
                max = time_slots[i];
            }
        }
        PrintWriter Out = new PrintWriter(new File("blist.out"));
        Out.printf("%s\n", max);
        Out.close();
    }
}
