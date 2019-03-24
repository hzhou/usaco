//Jasmine Zhang
//All cases passed in 20 minutes
import java.util.*;
import java.io.*;
public class cownomics {
	static int n;
	static String [] spotty;
	static String [] plain;
	public static void main(String[] args) throws IOException{
		
		
		Scanner scan = new Scanner (new File ("cownomics.in"));
		n = scan.nextInt();
		int length = scan.nextInt();
		
		scan.nextLine();
		spotty = new String [n];
		for (int i = 0; i < n; i++) {
			spotty[i] = scan.nextLine();
		}
		plain = new String [n];
		for (int i = 0; i < n; i++) {
			plain[i] = scan.nextLine();
		}
		
		int total = 0;
		for (int i = 0; i < length; i++) {
			if (canExplain(i))
				total++;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
		System.out.println(total);
		out.println(total);
	
		out.close();
		scan.close();
	}
	public static boolean canExplain (int in) {
		String spot = "";
		for (int i = 0; i < n; i++) {
			spot += spotty[i].charAt(in);
		}
		//System.out.println(spot);
		for (int i = 0; i < n; i++) {
			if (spot.indexOf(plain[i].charAt(in))>= 0){
				return false;
			}
		}
		return true;
	}

}
