
/*
Bill Zheng
1.5 hours
The USACO Submissions weren't actually working so I don't know if this code actually works...
I definitely need to work on making my codes less messy because that is what confused me the most when debugging,
	though the broken submissions didn't help at all.
 */

import java.io.*;
import java.util.*;

public class reststops {
	public static void main(String[] args) throws IOException {
		//BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\OldCode.Silver\\testSilver.txt"));
		// BufferedReader f = new BufferedReader(new FileReader("test.in"));

		//Scanner scan = new Scanner(new File("D:\\eclipse-workspace\\USACO\\OldCode.Silver\\testSilver.txt"));
		Scanner scan = new Scanner (new File ("reststops.in"));

		//StringTokenizer st = new StringTokenizer(scan.readLine());

		int L = scan.nextInt();
		int N = scan.nextInt();
		int rF = scan.nextInt();
		int rB = scan.nextInt();
		
		Stop[] S = new Stop[N];
		for (int i = 0; i < N; i++) {
			S[i] = new Stop(scan.nextInt(), scan.nextInt());
		}
		Arrays.sort(S);
		for (int i = 0; i < N; i++) {
			System.out.println("S[" + i + "] pos: " + S[i].pos + "; taste: " + S[i].taste);
		}
		//int[] T = new int[L];
		long time = 0;
		long diffT = 0;
		long ret = 0;
		Stop best = new Stop(0,0);
		int c = 0;
		int last = 0;
//------------------------------------------------------------------------------------------
		
		int j = 0;
		while (j < N) {
			c = 0;
			last = best.pos;
			best = S[j];
			System.out.println(best.pos + " " + best.taste);
			for (int i = j; i < N; i++) {
				if (S[i].taste > best.taste) {
					best = S[i];
					c = i;
				}
			}
			System.out.println("2: " + best.pos + " " + best.taste);
			time = (long)(best.pos-last)*rB;
			diffT = (long)(best.pos-last)*rF - time;
			ret += best.taste*diffT;
			System.out.println("time: " + time + "; diffT: " + diffT + "; ret: " + ret);
			if (c > 0) j = c; else j++;
		}
//------------------------------------------------------------------------------------------
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("reststops.out")));
		System.out.println(ret);
		out.println(ret);

		out.close();
		scan.close();
	}
}

class Stop implements Comparable <Stop>{
	public int pos, taste;
	public Stop(int pos, int taste) {
		this.pos = pos;
		this.taste = taste;
	}
	public int compareTo(Stop s) {
		return this.pos - s.pos;
	}
}
