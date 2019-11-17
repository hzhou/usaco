//Max Yang
//40 minutes
//All tests passed

import java.io.*;
import java.util.*;

public class notlast{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("notlast.in"));
                int N = scan.nextInt();
                int[] Cows = new int[7];
                String name = "";
		int milk=0;
                for(int i=0; i<N; i++){
                    name = scan.next();
		    milk=scan.nextInt();
                    if(name.equals("Bessie")) Cows[0]+=milk;
                    else if(name.equals("Elsie")) Cows[1]+=milk;               
                    else if(name.equals("Daisy")) Cows[2]+=milk;                  
                    else if(name.equals("Gertie")) Cows[3]+=milk;                  
                    else if(name.equals("Annabelle")) Cows[4]+=milk;                    
                    else if(name.equals("Maggie")) Cows[5]+=milk;                   
                    else Cows[6]+=milk;                  
                }
                scan.close();
    		
		//find min            
                int min=10000000;
                for(int i=0; i<7; i++){
                        if(Cows[i]<min) min=Cows[i];   
		    
                }
		//take out min
                for(int i=0; i<7; i++){
                        if(Cows[i]==min) Cows[i]=1000001;
                }

		//find 2nd min
                min=100000;
                for(int i=0; i<7; i++){
                        if(Cows[i]<min) min=Cows[i];
                }       
		
		//count 2nd min
		int count=0;
		for(int i=0; i<7; i++){
                        if(Cows[i]==min) count++;
                }
                PrintWriter out = new PrintWriter(new BufferedWriter (new FileWriter("notlast.out")));
                
                if(count==1){
                	for(int i=0; i<7; i++){
                                if(Cows[i]==min){
                                        if(i==0)  out.println("Bessie");
                                        if(i==1)  out.println("Elsie");           
                                        if(i==2)  out.println("Daisy");                 
                                        if(i==3)  out.println("Gertie");              
                                        if(i==4)  out.println("Annabelle");                   
                                        if(i==5)  out.println("Maggie");                  
                                        if(i==6)  out.println("Henrietta");        
                                }
                	}
		
		}
		else{
			out.println("Tie");
		}
		out.close();