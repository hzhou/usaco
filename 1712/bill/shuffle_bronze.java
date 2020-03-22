/*
Bill Zheng
~ 30 min
I just worked backwards for this problem and it was pretty straightforward from there.
 */

import java.io.*;
import java.util.*;

class shuffle {
	public static void main(String[] args) throws IOException {
		// BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\OldCode.Bronze\\test1.txt"));
		BufferedReader f = new BufferedReader(new FileReader("shuffle.in"));

		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());

		int num = Integer.parseInt(st.nextToken());

		int[] order = new int[num];
		st = new StringTokenizer(f.readLine());
		for (int i = 0; i < num; i++) {
			order[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(f.readLine());
		int[] cow1 = new int[num];
		for (int i = 0; i < num; i++) {
			cow1[i] = Integer.parseInt(st.nextToken());
		}
		int[] cow2 = new int[num];
		// shuffling
		System.out.println("Original: ");
		for (int i = 0; i < cow1.length; i++) {
			System.out.println(cow1[i]);
		}

		for (int i = 0; i < cow1.length; i++) {
			cow2[i] = cow1[order[i] - 1];
		}

		System.out.println("One shuffle: ");
		for (int i = 0; i < cow1.length; i++) {
			System.out.println(cow2[i]);
		}

		for (int i = 0; i < cow1.length; i++) {
			cow1[i] = cow2[order[i] - 1];
		}
		System.out.println("Two shuffle: ");
		for (int i = 0; i < cow1.length; i++) {
			System.out.println(cow1[i]);
		}

		for (int i = 0; i < cow1.length; i++) {
			cow2[i] = cow1[order[i] - 1];
		}
		System.out.println("Three shuffle: ");
		for (int i = 0; i < cow1.length; i++) {
			System.out.println(cow2[i]);
			out.println(cow2[i]);
		}

		out.close();
	}
}
