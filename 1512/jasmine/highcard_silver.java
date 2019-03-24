//Jasmine Zhang
//All cases passed in 20 minutes
import java.util.*;
import java.io.*;
public class highcard {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("highcard.in"));
		int n = scan.nextInt();
		
		int [] elsie = new int [n];
		HashSet <Integer> e = new HashSet <Integer>();
		for (int i = 0; i < n; i++) {
			elsie[i] = scan.nextInt();
			e.add(elsie[i]);
		}
		
		int [] bessie = new int [n];
		int in = 0;
		for (int i = 1; i <= 2*n; i++) {
			if (e.contains(i)) 
				continue;
			bessie[in] = i;
			in++;
		}
		
		Arrays.sort(elsie);
		Arrays.sort(bessie);
		
		int eIn = 0;
		int bIn = 0;
		int wins = 0;
		while (eIn < n && bIn < n) {
			int bes = bessie[bIn];
			int els = elsie[eIn];
			
			if (els > bes)
				bIn++;
			else {
				bIn++;
				eIn++;
				wins++;
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("highcard.out")));
		System.out.println(wins);
		out.println(wins);
	
		out.close();
		scan.close();
	}

}
