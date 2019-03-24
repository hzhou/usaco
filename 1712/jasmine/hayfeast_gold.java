//Jasmine Zhang

import java.util.*;
import java.io.*;
public class hayfeast {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("hayfeast.in"));
		int n = scan.nextInt();
		long m = scan.nextLong();
		
		long [] totalFlav = new long [n+1];
		int [] spice = new int [n];
		int [] flav = new int [n];
		
		int [] a = new int [100000];
		
		totalFlav[0] = 0;
		int minSpice = -1;
		for (int i = 0; i < n; i++) {
			int f = scan.nextInt();
			flav[i] = f;
			totalFlav[i+1] = f + totalFlav[i];
			spice[i] = scan.nextInt();
		}
		
		int [][] maxSpice = new int [n][n];
		for (int i = 0; i < n; i++)
			maxSpice[i][i] = spice[i];
		
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				maxSpice[i][j] = Math.max(spice[j], maxSpice[i][j-1]);
			}
			//System.out.println(Arrays.toString(maxSpice[i]));
		}
		
		long totFlav = flav[0];
		int b = 0;
		for (int i = 1; i < n; i++) {
			int f = flav[i];
			if (f + totFlav < m) {
				totFlav += f;
				continue;
			}
			int max = maxSpice[b][i];
			if (minSpice == -1 || max < minSpice)
				minSpice = max;
			
			totFlav += f;
			while (totFlav > m) {
				totFlav -= flav[b];
				b++;
			}
		}
		
		/*
		for (int i = 0; i < n; i++) {
			int max = spice[i];
			int add = 1;
			while (i+add <= n && totalFlav[i+add]-totalFlav[i] < m) {
				max = Math.max(spice[i+add-1], max);
				add++;
			}
			//System.out.println(i + " " + add);
			if (i+add <= n)
				max = Math.max(spice[i+add-1], max);
			else if (totalFlav[i+add-1]-totalFlav[i] < m) 
				max = -1;
			//System.out.println(totalFlav[i+add]-totalFlav[i]);
			if (max != -1 && (minSpice == -1 || max < minSpice)) {
				minSpice = max;
			}
		}
		*/
		
		   
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hayfeast.out")));
		System.out.println(minSpice);
		out.println(minSpice);
	
		out.close();
		scan.close();
	}

}
