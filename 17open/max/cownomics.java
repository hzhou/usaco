//Max Yang
//40 minutes
//All test passed

import java.io.*;
import java.util.*;

public class cownomics{
        public static void main(String[] args) throws IOException{
                Scanner scan = new Scanner(new File("cownomics.in"));
                int N=scan.nextInt(), M=scan.nextInt();
                String input;
                char[] spot = new char[N*M];
                char[] plain = new char[N*M];

                int count=0;
                for(int i=0; i<N; i++){
                        input = scan.next();
                        for(int j=0; j<M; j++){
                                spot[count+j] = input.charAt(j);
                        }
                        count+=M;
                }
                count=0;
                for(int i=0; i<N; i++){
                        input = scan.next();
                        for(int j=0; j<M; j++){
                                plain[count+j] = input.charAt(j);
                        }
                        count+=M;
                }
                scan.close();

                count=0;
                int end=0, win=0;
                int sA=0, sT=0, sC=0, sG=0;
                int pA=0, pT=0, pC=0, pG=0;
                for(int i=0; i<M; i++){
                        for(int j=0; j<N; j++){
                                if(spot[i+count]=='A')sA=1;
                                if(spot[i+count]=='T')sT=1;
                                if(spot[i+count]=='C')sC=1;
                                if(spot[i+count]=='G')sG=1;
                                count+=M;
                        }
                        count=0;
                        for(int j=0; j<N; j++){
                                if(plain[i+count]=='A')pA=1;
                                if(plain[i+count]=='T')pT=1;
                                if(plain[i+count]=='C')pC=1;
                                if(plain[i+count]=='G')pG=1;
                                count+=M;
                        }
                        if(sA==1&&pA==1)end++;
                        if(sT==1&&pT==1)end++;
                        if(sC==1&&pC==1)end++;
                        if(sG==1&&pG==1)end++;
                        if(end==0)win++;
                        end=0; count=0;
                        sA=0; sT=0; sC=0; sG=0;
                        pA=0; pT=0; pC=0; pG=0;
                }
                System.out.println(win);

                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
                out.println(win);
                out.close();
        }
}