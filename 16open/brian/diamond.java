// package diamond;

/* initial confusion of thinking that the difference k only mattered for the size
 * of two diamond next to each other. ate about 10 mins.
 * 
 * At around 20 realized trying finding the smaller diamond if the diamond was 
 * smaller than the one that was compared was going to be really weird.
 *
 * At around 22m done.. passed
 */
//package javaapplication17;

import java.util.*;
import java.io.*;

public class diamond {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("diamond.in"));
        int lines = sc.nextInt();
        int k = sc.nextInt();
        int[] diamonds = new int[lines];
        for (int i = 0; i < lines; i++) {
            diamonds[i] = sc.nextInt();
        }
        
        int max = 0;
        
        for (int i = 0; i < lines; i++) {
            int dcount = 0;
            for (int j = 0; j < lines; j++) {
                if (diamonds[j] >= diamonds[i] &&
                        diamonds[j] - diamonds[i] <= k) {
                    dcount++;
                }
            }
            if (dcount > max) {
                max = dcount;
            }
        }
        PrintWriter writer = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("diamond.out")
                    )
            );
        writer.println(String.valueOf(max));
        writer.close();
        System.out.println(max);
    }
    
}
