//Max Yang
//40 minutes
//8 tests passed
//Went through logic a couple times, but never found error for last 2 cases

import java.util.*;
import java.io.*;

public class lifeguards{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("lifeguards.in"));
                int N = scan.nextInt();

                int[] T = new int[1001];

                int[] Start = new int[N+1];
                int[] End = new int[N+1];

                for(int i=0; i<N; i++){
                        Start[i] = scan.nextInt();
                        End[i]=scan.nextInt();
                }

		//Initialization
                for(int i=0; i<N; i++){
                        for(int j=Start[i]; j<End[i]; j++){
                                T[j]++;
                        }
                }

                //Check
                int max=0;
                for(int j=0; j<N; j++){
                        //each lifeguard
			for(int k=Start[j]; k<End[j]; k++){
                                T[k]--;
                        }
                        //shifts per lifeguard fired
                        int count=0;
			for(int k=0; k<1001; k++){
                                if(T[k]>0) count++;
                        }
                        if(count>=max){
                                max=count;
                        }
			//reset
                        for(int k=Start[j]; k<End[j]; k++){
                                T[k]++;
                        }
 			count=0;

                }

                // max-=2;
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
		out.println(max);
		out.close();

        }
}
