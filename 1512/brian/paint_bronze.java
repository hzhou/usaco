import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Brian Lu
 * 61m 10s 709 ms
 * 
 * Why is the time so high? Because I was bad. The problem was simple enough to
 * have the test cases coded in, which took a little less than 10 mins to figure
 * out. The bloody submission though took like some 50 mins cause I completely 
 * forgot how I submitted last time. Turns out because I was just submitting a
 * single file, the package name at the top just wrecked everything. Well those
 * are some 50 mins that can teach a lesson...
 */
public class paint {

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("paint.in"));
            String[] tmp = sc.nextLine().split(" ");
            int a = Integer.parseInt(tmp[0]);
            int b = Integer.parseInt(tmp[1]);
            tmp = sc.nextLine().split(" ");
            int c = Integer.parseInt(tmp[0]);
            int d = Integer.parseInt(tmp[1]);
            
            int length;
            if (c <= a && d >= b) {
                length = d - c;
            } else if (a <= c && d <= b) {
                length = b - a;
            } else if (b > c && d > b) {
                length = d - a;
            } else if (d > a && b > d) {
                length = b - c;
            } else {
                length = (b - a) + (d - c);
            }
            
            PrintWriter writer = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("paint.out")
                    )
            );
            writer.println(String.valueOf(length));
            writer.close();
        } catch (FileNotFoundException ex) {
        } catch (IOException ex) {}
    }
}
