//Jasmine Zhang
//All cases passed in 15 minutes 
import java.util.*;
import java.io.*;
public class hps {
	
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("hps.in"));
		int n = scan.nextInt();
		
		/*
		 *  2 cases
		 *  (count1)	(count2)
		 *  1 beat 2	1 beat 3
		 *  2 beat 3	2 beat 1
		 *  3 beat 1	3 beat 2
		 */
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < n; i++) {
			int cow1 = scan.nextInt();
			int cow2 = scan.nextInt();
			if (cow1 == cow2)
				continue;
			if (cow1 == 1) {
				if (cow2 == 2)
					count1++;
				else 
					count2++;
			}
			else if (cow1 == 2) {
				if (cow2 == 3)
					count1++;
				else 
					count2++;
			}
			else  {
				if (cow2 == 1)
					count1++;
				else 
					count2++;
			}
					
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hps.out")));
		out.println(Math.max(count1, count2));
		
		
		out.close();
		scan.close();

	}

}
