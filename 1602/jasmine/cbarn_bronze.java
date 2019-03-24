//14 minutes 
import java.util.*;
import java.io.*;
public class cbarn {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("cbarn.in"));
		int n = scan.nextInt();
		
		int [] rooms = new int [n];
		for (int i = 0; i < n; i++)
			rooms[i] = scan.nextInt();
		
		int min = -1;
		for (int i = 0; i < n; i++) {
			int totalSteps = 0;
			int c = 1;
			for (int j = i + 1; j < i + n; j++) {
				totalSteps += rooms[j%n]*c;
				c++;
			}
			if (min == -1)
				min = totalSteps;
			else if (totalSteps < min)
				min = totalSteps;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cbarn.out")));
		System.out.println(min);
		out.println(min);
		
	
		out.close();
		scan.close();
	}

}
