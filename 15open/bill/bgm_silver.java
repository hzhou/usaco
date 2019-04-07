
/*
Bill Zheng
//1 hour
//I tried the slow way first, then did a faster way	
Tests: ***xxxxxxx
 */

import java.io.*;
import java.util.*;

public class bgm {
	public static void main(String[] args) throws IOException {
		//Scanner scan = new Scanner(new File("D:\\eclipse-workspace\\USACO\\Silver\\testSilver.txt"));
		Scanner scan = new Scanner (new File ("bgm.in"));

		// ------------------------------------------------------------------------------------------
		int N = scan.nextInt();
		int[] b = new int[7];
		int[] e = new int[7];
		int[] s = new int[7];
		int[] i = new int[7];
		int[] g = new int[7];
		int[] o = new int[7];
		int[] m = new int[7];
		
		for (int j = 0; j < N; j++) {
			String next = scan.next();
			if (next.equals("B")) b[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("E")) e[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("S")) s[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("I")) i[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("G")) g[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("O")) o[((scan.nextInt()%7)+7)%7]++;
			if (next.equals("M")) m[((scan.nextInt()%7)+7)%7]++;
		}
		// ------------------------------------------------------------------------------------------
		long ret = 0;
		for (int B = 0; B < 7; B++)
		for (int E = 0; E < 7; E++)
		for (int S = 0; S < 7; S++)
		for (int I = 0; I < 7; I++)
		for (int G = 0; G < 7; G++)
		for (int O = 0; O < 7; O++)
		for (int M = 0; M < 7; M++) {
			if (((B+E+S+S+I+E)*(G+O+E+S)*(M+O+O)) % 7 == 0) {
				ret += b[B] * e[E] * s[S] * i[I] * g[G] * o[O] * m[M];
			}
		}
		// ------------------------------------------------------------------------------------------
		//Slow Version
		/*
		for (int i = 0; i < B.size(); i++) {
			for (int j = 0; j < I.size(); j++) {
				for (int k = 0; k < S.size(); k++) {
					for (int l = 0; l < E.size(); l++) {
						total = B.get(i) + I.get(j) + 2 * S.get(k) + 2 * E.get(l);
						// System.out.println("BESSIE: " + total);
						if (total % 7 == 0 && total != 0) {
							System.out.println("BESSIE: " + total);
							ret += G.size() * O.size() * M.size();
						}
					}
				}
			}
		}
		for (int i = 0; i < G.size(); i++) {
			for (int j = 0; j < O.size(); j++) {
				for (int k = 0; k < E.size(); k++) {
					for (int l = 0; l < S.size(); l++) {
						total = G.get(i) + I.get(j) + E.get(k) + S.get(l);
						// System.out.println("GOES: " + total);
						if (total % 7 == 0 && total != 0) {
							System.out.println("GOES: " + total);
							ret += B.size() * I.size() * M.size();
						}
					}
				}
			}
		}
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < O.size(); j++) {
				total = M.get(i) + 2 * O.get(j);
				// System.out.println("MOO: " + total);
				if (total % 7 == 0 && total != 0) {
					System.out.println("MOO: " + total);
					ret += B.size() * I.size() * E.size() * S.size() * G.size();
				}
			}
		}
		*/
		// ------------------------------------------------------------------------------------------

		// ------------------------------------------------------------------------------------------

		// ------------------------------------------------------------------------------------------

		// ------------------------------------------------------------------------------------------

		// ------------------------------------------------------------------------------------------
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bgm.out")));
		System.out.println(ret);
		out.println(ret);

		out.close();
		scan.close();
	}
}
