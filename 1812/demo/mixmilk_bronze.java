
import java.io.*;
import java.util.*;

public class mixmilk_bronze {

    public static void main(String[] args) throws IOException
    {

        int A, a, B, b, C, c;
        Scanner In = new Scanner(new File("mixmilk.in"));
        A = In.nextInt();
        a = In.nextInt();
        B = In.nextInt();
        b = In.nextInt();
        C = In.nextInt();
        c = In.nextInt();

        for (int  i = 0; i<100; i++) {
            if (i % 3 == 0) {
                if (a + b <= B) {
                    b += a;
                    a = 0;
                } else {
                    a = a+b-B;
                    b = B;
                }
            } else if (i % 3 == 1) {
                if (b + c <= C) {
                    c += b;
                    b = 0;
                } else {
                    b = b+c-C;
                    c = C;
                }
            } else if (i % 3 == 2) {
                if (c + a <= A) {
                    a += c;
                    c = 0;
                } else {
                    c = c+a-A;
                    a = A;
                }
            }
        }

        PrintWriter Out = new PrintWriter(new File("mixmilk.out"));
        Out.printf("%s\n", a);
        Out.printf("%s\n", b);
        Out.printf("%s\n", c);
        Out.close();
    }
}
