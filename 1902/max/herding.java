import java.io.*;
import java.util.*;

public class herding{
        public static void main(String[] args) throws IOException{
                Scanner scan = new Scanner(new File("herding.in"));

                int first = scan.nextInt();
                int mid = scan.nextInt();
                int last = scan.nextInt();

                int holder = 0;

                //order
                if(last<first){
                        holder = first;
                        first = last;
                        last = holder;
                }
                if(last<mid){
                        holder = mid;
                        mid = last;
                        last = holder;
                }

                scan.close();

                int min=0, max=0;

                if(mid==first+2||last==mid+2)
                        min=1;
                else if(last==mid+1&&mid==first+1)
                        min=0;
                else
                        min=2;

                if(last-mid>=mid-first)
                        max=last-mid-1;
                else
                        max=mid-first-1;

                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("herding.out")));
                out.println(min);
                out.println(max);
                out.close();
        }
}
