//Jasmine Zhang
//All cases passed in 5 minutes 
import java.util.*;
import java.io.*;
public class paint {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("paint.in"));
		int a = scan.nextInt();
		int b = scan.nextInt();
		
		int c = scan.nextInt();
		int d = scan.nextInt();
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
		
		//two corner cases:
		//1. Bessie's area and Farmer John's area don't overlap
		//2. Bessie and Farmer John paint the same area
		
		//Need to have equals in case Bessie and Farmer John have the same area
		if ((a <= c && b >= c) //Bessie  overlaps to the right
				|| (c <= a && d >= a)) //Bessie overlaps to the left
			out.println(Math.max(d, b)- Math.min(a,c)); 
		else //no overlap
			out.println((d-c) + (b-a));
	
		out.close();
		scan.close();
	}

}
