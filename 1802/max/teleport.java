//Max Yang
//25 minutes
//All tests passed
//Found general code fast with some case testing
import java.io.*;
import java.util.*;


public class teleport{
        public static void main(String[] args) throws IOException{
                Scanner scan = new Scanner(new File("teleport.in"));
                int a=scan.nextInt();
                int b=scan.nextInt();
                int x=scan.nextInt();
                int y=scan.nextInt();
                scan.close();

                int temp=0, ans=0;
                if(y<x){
                        temp=y;
                        y=x;
                        x=temp;
                }
		if(b<a){
                        temp=b;
                        b=a;
                        a=temp;
                }

                int manual=Math.abs(b-a);
                int teleport=Math.abs(x-a)+Math.abs(y-b);

                if(manual<=teleport){ans=manual;}
                else{ans=teleport;}

                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
                out.println(ans);
		out.close();
        }
}