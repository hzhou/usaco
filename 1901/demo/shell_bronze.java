
import java.io.*;
import java.util.*;

public class shell_bronze {

    public static void main(String[] args) throws IOException
    {
        int N;
        Scanner In = new Scanner(new File("shell.in"));
        N = In.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] G = new int[N];
        for (int  i = 0; i<N; i++) {
            A[i] = In.nextInt();
            B[i] = In.nextInt();
            G[i] = In.nextInt();
            A[i]--;
            B[i]--;
            G[i]--;
        }
        int[] poss = new int[3];
        int[] wins = new int[3];
        for (int  j = 0; j<3; j++) {
            poss[j] = j;
        }
        for (int  i = 0; i<N; i++) {
            for (int  j = 0; j<3; j++) {
                if (poss[j] == A[i]) {
                    poss[j] = B[i];
                } else if (poss[j] == B[i]) {
                    poss[j] = A[i];
                }
                if (G[i] == poss[j]) {
                    wins[j]++;
                }
            }
        }
        int max = 0;
        for (int  j = 0; j<3; j++) {
            if (max < wins[j]) {
                max = wins[j];
            }
        }
        PrintWriter Out = new PrintWriter(new File("shell.out"));
        Out.printf("%d\n", max);
        Out.close();
    }
}
