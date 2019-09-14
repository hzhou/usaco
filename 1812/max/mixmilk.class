//Max Yang
//35 minutes
//All tests passed
//Spent most time on debugging conditions and learning how to input and output files
import java.io.*;
import java.util.*;

public class mixmilk {
        public static void main(String[] args) throws IOException{
                Scanner scan = new Scanner(new File ("mixmilk.in"));
                int ac = scan.nextInt();
                int am = scan.nextInt();
                int bc = scan.nextInt();
                int bm = scan.nextInt();
                int cc = scan.nextInt();
                int cm = scan.nextInt();
                scan.close();


                int j = 0;
                for(int i = 0; i<100; i++){
                        j = i%3;
                        if(j==0){
                                //a to b
                                if(am+bm<=bc){  //if a becomes empty
                                        bm += am;
                                        am = 0;
                                }
                                if(am+bm>bc){  //if b becomes full
                                        am -= (bc-bm);
                                        bm = bc;
                                }
                        }
                        else if(j==1){
                                //b to c
                                if(bm+cm<=cc){
                                        cm += bm;
                                        bm = 0;
                                }
                                if(bm+cm>cc){
                                        bm = bm-(cc-cm);
                                        cm = cc;
                                }
                        }
                        else{
                                //c to a
                                if(cm+am<=ac){
                                        am += cm;
                                        cm = 0;
                                }
                                if(bm+cm>ac){
                                        cm -= (ac-am);
                                        am = ac;
                                }
                        }
                }


                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("mixmilk.out")));
                out.println(am);
		out.println(bm);
		out.println(cm);
                out.close();
        }
}