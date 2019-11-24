//Max Yang
//35 minutes
//All tests passed

import java.io.*;
import java.util.*;

public class notlast{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("hps.in"));
                int N = scan.nextInt();
                int[] A = new int[N+1];
                int[] B = new int[N+1]'
                
                for(int i=0; i<N; i++){
                    A[i] = scan.nextInt();
                    B[i] = scan.nextInt();
                }
                scan.close();
                
                int win1=0, win2=0;
                for(int i=0; i<N; i++){
                    if(A[i]==1){
                        if(B[i]==2) win1++;
                        if(B[i]==3) win2++;
                    }
                    if(A[i]==2){
                        if(B[i]==3) win1++;
                        if(B[i]==1) win2++;
                    }
                    if(A[i]==3){
                        if(B[i]==1) win1++;
                        if(B[i]==2) win2++;
                    }
                }
                
                PrintWriter out = new PrintWriter(new BufferedWriter (new FileWriter("hps.out")));
                if(win1>win2) out.println(win1);
                if(win2>win1) out.println(win2);
                out.close();
        }
}
