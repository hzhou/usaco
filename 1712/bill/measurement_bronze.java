/*
Bill Zheng
~ 40 min
This problem was very straight forward, just took some time to write out and debug.
 */

import java.io.*;
import java.util.*;

class measurement {
	public static void main(String[] args) throws IOException {
		//BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\OldCode.Bronze\\test1.txt"));
		BufferedReader f = new BufferedReader(new FileReader("measurement.in"));

		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());

		int N = Integer.parseInt(st.nextToken());
		ArrayList<String> s = new ArrayList<String>();
		int[][] a = new int[N][3];
		String B = "Bessie";
		String E = "Elsie";
		String M = "Mildred";
		s.add(B);
		s.add(E);
		s.add(M);
		int b = 7;
		int e = 7;
		int m = 7;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(f.readLine());
			a[i][0] = Integer.parseInt(st.nextToken());
			String name = st.nextToken();
			if (name.equals("Bessie")) {
				a[i][1] = 1;
			} else if (name.equals("Elsie")) {
				a[i][1] = 2;
			} else if (name.equals("Mildred")) {
				a[i][1] = 3;
			}
			a[i][2] = Integer.parseInt(st.nextToken());
		}
		int ret = 0;
		int min = Integer.MAX_VALUE;
		int ind = 0;
		int count = 0;
		
		for (int k = 0; k < N; k++) {
			min = Integer.MAX_VALUE;
			count = 0;
			for (int i = 0; i < N; i++) {
				//System.out.println("a[i][0]: " + a[i][0]);
				if (a[i][0] < min) {
					min = a[i][0];
					//System.out.println("Min in: " + min);
					ind = i;
				}
			}
			a[ind][0] = Integer.MAX_VALUE;
			//System.out.println("Min: " + min);
			//System.out.println("Ind: " + ind);
			
			if (a[ind][1] == 1) {
				b += a[ind][2];
				if (b < 0) {
					b = 0;
				}
			} else if (a[ind][1] == 2) {
				e += a[ind][2];
				if (e < 0) {
					e = 0;
				}
			} else if (a[ind][1] == 3) {
				m += a[ind][2];
				if (m < 0) {
					m = 0;
				}
			}
			int max = Math.max(m, Math.max(b, e));
			//System.out.println("Max: " + max);
			if (b == max) {
				if (!s.contains(B)) {
					s.add(B);
					count++;
				}
			} else {
				if (s.contains(B)) {
					s.remove(B);
					count++;
				}
			}
			if (e == max) {
				if (!s.contains(E)) {
					s.add(E);
					count++;
				}
			} else {
				if (s.contains(E)) {
					s.remove(E);
					count++;
				}
			}
			if (m == max) {
				if (!s.contains(M)) {
					s.add(M);
					count++;
				}
			} else {
				if (s.contains(M)) {
					s.remove(M);
					count++;
				}
			}
			if (count > 0) {
				ret++;
			}
		}
		System.out.println(ret);
		out.println(ret);
		out.close();
	}
}
