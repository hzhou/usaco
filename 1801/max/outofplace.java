//Max Yang
//40 minutes
//All tests passed
//Took some time writing out problem but solved
import java.io.*;
import java.util.*;

public class outofplace{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("outofplace.in"));
                int N = scan.nextInt();
                int[] Cows = new int[N+1];
                int[] Sorted = new int[N+1];

                int total=0;
                for(int i=0; i<N; i++){
                        Cows[i] = scan.nextInt();
                        Sorted[i]=Cows[i];
                        total++;
                }

                int temp, count=0, bool=0;
                while(bool==0){
                        for(int i=0; i<N; i++){
                //              System.out.println(Sorted[i] + "vs. " + Sorted[i+1]);
                                if(Sorted[i]==Sorted[N-1]);
                                else if(Sorted[i]>Sorted[i+1]){
                                        temp = Sorted[i];
                                        Sorted[i]=Sorted[i+1];
                                        Sorted[i+1]=temp;
                                }
                //              System.out.println("Sorted[" + i + "] is now " + Sorted[i]);
                        }
                        for(int j=0; j<N; j++){
                                if(Sorted[j]<=Sorted[j+1]) count++;
                                if(count==total-1) bool=1;
                        }
                        count=0;
                }



                int change=0;
                for(int i=0; i<N; i++){
                //      System.out.print(Sorted[i]);
                       if(Sorted[i]!=Cows[i]) change++;
                }

                System.out.println(change-1);
		PrintWriter out = new PrintWriter(new BufferedWriter (new FileWriter("outofplace.out")));
                out.println(change-1);
                out.close();

        }
}