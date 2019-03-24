/**
 *
 * about 40 mins
 * TIMED OUT!: ********tt
 * 
 * I decided to start at the end of the circle going counter-clockwise back in 
 * time instead of forwards because I didn't know how to calculate distance from
 * going forwards.
 * 
 * A decent chunk of time was trying to get my index "circularizer" (overflow 
 * thing?) to work, which I eventually just ripped off of Stack Overflow.
 * 
 * @author Brian Lu
 */

import java.io.*;
import java.util.*;

public class cbarn {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("cbarn.in"));
        int len = sc.nextInt();
        int[] rooms = new int[len];
        for (int i = 0; i < len; i++) {
            rooms[i] = sc.nextInt();
        }
        int mindist = Integer.MAX_VALUE - 1;
        for (int i = 0; i < rooms.length; i++) {
            int cows = 0;
            int distance = 0;
            for (int j = rooms.length - 1; j >= 0; j--) {
                /*
                int index = i + j;
                if (index > rooms.length - 1) {
                    index = index - (rooms.length-1);
                }
                */
                int index = (j+i) % rooms.length; //Stackoverflow i guess
                
                cows += rooms[index];
                if (!(j == 0)) {
                    distance += cows;
                }
                System.out.println(j + "\t" + index);
            }
            System.out.println(distance);
            if (distance < mindist) {
                System.out.println("ran");
                mindist = distance;
            }
        }
       PrintWriter writer = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("cbarn.out")
                    )
            );
        writer.println(String.valueOf(mindist));
        writer.close();
        
        System.out.println(mindist);
    }

}
