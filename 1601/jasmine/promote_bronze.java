//Jasmine Zhang
//42 minutes
//Took me very long to come up with a way to solve the problem
//First solution was way too complicated - had too many if statements and used while loops
//Took me a long time to realized I was printing the promotion order backwards

import java.util.*;
import java.io.*;
public class promote {

	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("promote.in"));
		int [] working = new int [4];
		int [] after = new int [4];
		
		for (int i = 0; i < 4; i++) {
			int b = scan.nextInt();
			int a = scan.nextInt();
			working[i] = b;
			after[i] = a;
		}
		
		
		int [] order = new int [3]; 
 		for (int i = 3; i >=1; i--) { //originally printed in the for loop
 			after[0] = Integer.MAX_VALUE; //infinite amount of people could join
 			int diff = after[i]-working[i];
 			order [i-1] = diff;
 			working[i-1] -= diff;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("promote.out")));
		for (int i = 0; i < 3; i++) 
			out.println(order[i]);
		
	
		out.close();
		scan.close();
	}

}
