
/*
Bill Zheng
//1.5 hours
//My code is extremely messy because I sorted the cows by starting time first, then by length of time.
 * Is there any way to sort this easier?
 * Also I had to convert between data structures which ruined the readability of my code.
Tests: *******x**
 */

import java.io.*;
import java.util.*;

class CowChicken implements Comparable<CowChicken>{
	public int start, length;
	public CowChicken() {}
	public CowChicken(int start, int length) {
		this.start = start;
		this.length = length;
	}
	public int compareTo(CowChicken c) {
		return this.start - c.start;
	}
}
class CowChicken2 implements Comparable<CowChicken2>{
	public int start, length;
	public CowChicken2() {}
	public CowChicken2(int start, int length) {
		this.start = start;
		this.length = length;
	}
	public int compareTo(CowChicken2 c) {
		return this.length - c.length;
	}
}

public class helpcross_silver {
	public static void main(String[] args) throws IOException {
		//Scanner scan = new Scanner(new File("D:\\eclipse-workspace\\USACO\\Silver\\testSilver.txt"));
		Scanner scan = new Scanner (new File ("helpcross.in"));
		
//------------------------------------------------------------------------------------------
		int C = scan.nextInt();
		int N = scan.nextInt();
		
		int[] Ch = new int[C];
		for (int i = 0; i < C; i++) {
			Ch[i] = scan.nextInt();
		}
		CowChicken[] Cow = new CowChicken[N];
		for (int i = 0; i < N; i++) {
			int strt = scan.nextInt();
			int end = scan.nextInt();
			Cow[i] = new CowChicken(strt,end-strt);
		}
		Arrays.sort(Ch);
		Arrays.sort(Cow);
//------------------------------------------------------------------------------------------
		CowChicken2[] Cows = new CowChicken2[N];
		for (int i = 0; i < N; i++) {
			Cows[i] = new CowChicken2(Cow[i].start, Cow[i].length);
		}
		Arrays.sort(Cows);
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < C; i++) {
			list.add(Ch[i]);
		}
//------------------------------------------------------------------------------------------
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < list.size(); j++) {
				if (Cows[i].start <= list.get(j) && list.get(j) <= Cows[i].start+Cows[i].length) {
					count++;
					list.remove(j);
					// System.out.println("i: " + Cows[i].start + "; j: " + j + "; count: " + count);
					break;
				}
			}
		}
//------------------------------------------------------------------------------------------
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("helpcross.out")));
		System.out.println(count);
		out.println(count);

		out.close();
		scan.close();
	}
}
