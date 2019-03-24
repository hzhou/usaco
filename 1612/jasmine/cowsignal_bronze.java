//Jasmine Zhang
//All cases passed, 20 minutes
import java.util.*;
import java.io.*;
public class cowsignal {
	static int c;
	static int m;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("cowsignal.in"));
		int r = scan.nextInt();
		c = scan.nextInt();
		m = scan.nextInt();
		
		scan.nextLine();
		String [] sig = new String [r];
		for (int i = 0; i < r; i++)
			sig[i] = scan.nextLine();
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowsignal.out")));
		for (int i = 0; i < r; i++) {
			String row = row(sig[i]);
			for (int j = 0; j < m; j++) 
				out.println(row);
		}
		
		out.close();
		scan.close();
	}
	public static String row (String s) {
		String row = "";
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < m; j++) 
				row += s.charAt(i);
		}
		return row;
	}
}
