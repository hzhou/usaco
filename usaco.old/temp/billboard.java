
import java.io.*;
import java.util.Scanner;

public class billboard {
    public static void main(String[] args) throws IOException {
        int Ax1;
        int Ay1;
        int Ax2;
        int Ay2;
        int Bx1;
        int By1;
        int Bx2;
        int By2;
        int Cx1;
        int Cy1;
        int Cx2;
        int Cy2;
        Scanner scanner;
        PrintWriter out;
        scanner = new Scanner(new File("billboard.in"));
        Ax1 = scanner.nextInt();
        Ay1 = scanner.nextInt();
        Ax2 = scanner.nextInt();
        Ay2 = scanner.nextInt();
        Bx1 = scanner.nextInt();
        By1 = scanner.nextInt();
        Bx2 = scanner.nextInt();
        By2 = scanner.nextInt();
        Cx1 = scanner.nextInt();
        Cy1 = scanner.nextInt();
        Cx2 = scanner.nextInt();
        Cy2 = scanner.nextInt();
        System.out.printf("  :| Ax1=%s, Ay1=%s, Ax2=%s, Ay2=%s\n", Ax1, Ay1, Ax2, Ay2);
        int area;
        area = (Ax2 - Ax1) * (Ay2 - Ay1);
        area += (Bx2 - Bx1) * (By2 - By1);
        int w;
        int h;
        w = Math.max(0, Math.min(Ax2, Cx2) - Math.max(Ax1, Cx1));
        h = Math.max(0, Math.min(Ay2, Cy2) - Math.max(Ay1, Cy1));
        area -= w * h;
        w = Math.max(0, Math.min(Bx2, Cx2) - Math.max(Bx1, Cx1));
        h = Math.max(0, Math.min(By2, Cy2) - Math.max(By1, Cy1));
        area -= w * h;
        System.out.printf("  :| area=%s\n", area);
        out = new PrintWriter(new File("billboard.out"));
        out.printf("%d\n", area);
        out.close();
    }

}
