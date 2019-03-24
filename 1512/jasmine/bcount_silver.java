//Jasmine Zhang
//All cases passed in 30 minutes
import java.util.*;
import java.io.*;
public class bcount {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("bcount.in"));
		//buffer case 0 0 0
		int n = scan.nextInt();
		int q = scan.nextInt();
		
		long [] numB = new long [n+1];
		numB[0] = 0;
		for (int i = 1; i <= n; i++) {
			int b = scan.nextInt();
			//check to see if this works for big numbers;
			numB[i] = (long) (numB[i-1] + 1*Math.pow(100000, b-1));
		}
		//System.out.println(Arrays.toString(numB));
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bcount.out"))); 
		for (int i = 0; i < q; i++) {
			long begin = numB[scan.nextInt()-1]; 
			long end = numB[scan.nextInt()];
			
			long total = end - begin;
			//System.out.println(total);
			int a = (int) (total%100000);
			total /= 100000;
			int b = (int) (total%100000);
			total /= 100000;
			int c = (int) (total%100000);
			//System.out.println(a + " " + b + " " + c);
			out.println(a + " " + b + " " + c);
			 
		}
		
		
		
		
		
		
	
		out.close();
		scan.close();
	}
	

}
