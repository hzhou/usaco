
import java.io.*;
import java.util.*;

public class sleepy_bronze {

    public static void main(String[] args) throws IOException
    {
        int N;
        Scanner In = new Scanner(new File("sleepy.in"));
        N = In.nextInt();
        int[] P = new int[N];
        for (int  i = 0; i<N; i++) {
            P[i] = In.nextInt();
            P[i]--;
        }
        int i_pos = 0;
        for (int  i = N-1; i >= 1; i--) {
            if (P[i] < P[i-1]) {
                i_pos = i;
                break;
            }
        }
        PrintWriter Out = new PrintWriter(new File("sleepy.out"));
        Out.printf("%d\n", i_pos);
        Out.close();
    }
}
