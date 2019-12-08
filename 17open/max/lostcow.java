//Max Yang
//50 minutes
//All tests passed

import java.io.*;
import java.util.*;

public class lostcow{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("lostcow.in"));

                int initial_x = scan.nextInt();
                int y = scan.nextInt();
                int move=1, count=0;
                int x=initial_x;
                scan.close();
                int test=0;
                if(x<y){
                        for(int i=0; i<1000; i++){
                                x+=move;
                                count+=Math.abs(move)*2;
                                if(x>y||x==y)break;
                                move*=-2;
                                //count+=Math.abs(move)*2;
                                x=initial_x;

                        }
                        if(x!=y) count=count-(x-y)-(Math.abs(move));
                        else count=count-Math.abs(move);
                }
                else if(x>y){
                        for(int i=0; i<1000; i++){
                                x+=move;
                                count+=Math.abs(move*2);
                                if(x<y||x==y)break;
                                move*=-2;
                                x=initial_x;

                        }
                        if(x!=y) count = count-(y-x)-(Math.abs(move));
                        else count = count-Math.abs(move);
                }
                else count=0;

                System.out.println(count);
                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lostcow.out")));
                out.println(count);
		out.close();

	}
}