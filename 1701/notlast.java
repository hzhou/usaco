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
                    if(name.equals("Bessie")) Cows[0]++;
                    if(name.equals("Elsie")) Cows[1]++;               
                    if(name.equals("Daisy")) Cows[2]++;                  
                    if(name.equals("Gertie")) Cows[3]++;                  
                    if(name.equals("Annabelle")) Cows[4]++;                    
                    if(name.equals("Maggie")) Cows[5]++;                   
                    if(name.equals("Henrietta")) Cows[6]++;                  
                }
                scan.close();
                
                int min=100;
                for(int i=0; i<7; i++)
                        if(Cows[i]<min) min=Cows[i];       
                 
                for(int i=0; i<7; i++){
                        if(Cows[i]==min) Cows[i]=101;
                        
                min=100;
                for(int i=0; i<7; i++)
                        if(Cows[i]<min) min=Cows[i];
                       
                
                PrintWriter out = new PrintWriter(new BufferedWriter (new FileWriter("notlast.out")));
                
                if(min==0||min>1) out.println("Tie");
                else{
                        for(int i=0; i<7; i++){
                                if(Cows[i]==min){
                                        if(i==0)  out.println("Bessie");
                                        if(i==1)  out.println("Elsie");           
                                        if(i==2)  out.println("Daisy");                 
                                        if(i==3)  out.println("Gertie");              
                                        if(i==4)  out.println("Annabelle");                   
                                        if(i==5)  out.println("Maggie");                  
                                        if(i==6)  println("Henrietta");        
                                }
                        }
                }
          }
 }
