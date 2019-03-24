import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Brian Lu
 * 
 * Finished in 23m 20s 624ms
 * 
 * Having the code from FencePainting to arrgh fix the file submission was nice.
 * I haven't actually worked with Java extensively for a little while and I keep
 * trying to initialize variables like in Python, which sorta slows me down. 
 * Another issue with not working with this for some time is that I completely 
 * forgot that Arrays.fill() existed for a while.
 * I don't actually know if its a good idea to initialize limit and speed inside
 * the loop? I remember that certain things like that would just use more memory
 * than necessary. :/
 * Making the scan() method helped to clean up code a bit.
 */
public class speeding {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("speeding.in"));
        int[] road = new int[100];
        int[] bess = new int[100];
        int[] loopTimes = scan(sc);
        int index = 0;
        for (int i = 0; i < loopTimes[0]; i++) {
            int[] limit = scan(sc);
            Arrays.fill(road, index, index + limit[0], limit[1]);
            index += limit[0];
        }
        index = 0;
        for (int i = 0; i < loopTimes[1]; i++) {
            int[] speed = scan(sc);
            Arrays.fill(bess, index, index + speed[0], speed[1]);
            index += speed[0];
        }
        int aboveLimit = 0;
        for (int i = 0; i < 100; i++) {
            int diff = bess[i] - road[i];
            if (diff > aboveLimit) {
                aboveLimit = diff;
            }
        }
        
        PrintWriter writer = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("speeding.out")
                    )
            );
        writer.println(String.valueOf(aboveLimit));
        writer.close();
    }
    
    static int[] scan(Scanner sc, String seperator) {
        String scan = sc.nextLine();
        String[] temp = scan.split(seperator);
        int[] out = new int[temp.length];
        for (int i = 0; i < temp.length; i++) {
            out[i] = Integer.parseInt(temp[i]);
        }
        return out;
    }
    
    static int[] scan (Scanner sc) {
        return scan(sc, " ");
    }
}
