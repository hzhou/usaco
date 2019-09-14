//Max Yang
//40 minutes
//All tests passed
//Spent some time with arrays but not much debugging
import java.io.*;
import java.util.*;

public class blist{
        public static void main(String[] args) throws IOException{
                Scanner scan = new Scanner(new File("blist.in"));
                int s = 0, t = 0, b = 0;

                int N = scan.nextInt();

                int[] arr = new int[1001];

                for(int i = 0; i < N; i++){
                        s = scan.nextInt();
                        t = scan.nextInt();
                        b = scan.nextInt();

                        for(int j = s; j < t; j++){
                                arr[j] = arr[j]+b;
                        }
                }
                scan.close();

                int max = 1;
                for (int i = 0; i<arr.length;i++){
                        if(arr[i] > max){
                                max = arr[i];

                        }
                }

                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blist.out")));
                out.println(max);
                out.close();


        }
}