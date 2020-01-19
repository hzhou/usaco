
import java.io.*;
import java.util.*;

public class perm {

    public static void main(String[] args)
    {

        System.out.println("Hello World!");

        int[] P = new int[4];
        for (int  i = 0; i<4; i++) {
            P[i] = i;
        }

        perm(P, 4, 0);
    }

    public static void perm(int[] P, int N, int pos)
    {
        if (pos == N - 1) {
            for (int  i = 0; i<N; i++) {
                System.out.printf("%d ", P[i]);
            }
            System.out.println();
        }
        for (int  i = pos; i<N; i++) {
            int[] P_copy = new int[N];
            for (int  i2 = 0; i2<N; i2++) {
                P_copy[i2] = P[i2];
            }
            int tmp = P_copy[pos];
            P_copy[pos] = P_copy[i];
            P_copy[i] = tmp;
            perm(P_copy, N, pos + 1);
        }
    }
}
