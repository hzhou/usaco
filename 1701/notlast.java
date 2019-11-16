//Max Yang

import java.io.*;
import java.util.*;

public class notlast{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("notlast.in"));
                int N = scan.nextInt();
                int[] Cows = new int[7];
                String name = "";
                for(int i=0; i<N; i++){
                    name = scan.next();
                    if(name.equals("Bessie")){
                        Cows[0]++;
                    }
                    if(name.equals("Elsie")){
                        Cows[1]++;
                    }
                    if(name.equals("Daisy")){
                        Cows[2]++;
                    }
                    if(name.equals("Gertie")){
                        Cows[3]++;
                    }
                    if(name.equals("Annabelle")){
                        Cows[4]++;
                    }
                    if(name.equals("Maggie")){
                        Cows[5]++;
                    }
                    if(name.equals("Henrietta")){
                        Cows[6]++;
                    }
                }
               
         }
 }
