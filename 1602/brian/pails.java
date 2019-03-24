/**
 * about 26 m
 * 
 * I'm still using for loops to generate possibilities, should probably generate
 * permutations in a fancier fashion.
 * Is there a way to solve this problem algebraically? I'm not sure?
 * 
 * @author Brian Lu
 */

import java.io.*;
import java.util.*;

public class pails {

    public static void main(String[] args) throws IOException {
        
        Scanner sc = new Scanner(new File("pails.in"));
        
        int x = sc.nextInt();
        int y = sc.nextInt();
        int m = sc.nextInt();
        
        int max = 0;
        int fill;
        
        yloop:
        for (int yi = 0; yi <= Math.floor(m/y); yi++) {
            for (int xi = 0; xi <= Math.floor(m/x); xi++) {
                fill = yi * y + xi * x;
                if (fill <= m && fill > max) {
                    max = fill;
                }
                if (max == m) {
                    break yloop;
                }
            }
        }
        
        PrintWriter writer = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("pails.out")
                    )
            );
        writer.println(String.valueOf(max));
        writer.close();
        System.out.println(max);
    }
    
}
