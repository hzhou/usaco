// package com.bronze.feb2018;

/*
 * Harrison Zhang
 * Tests Passed: 1,2,4,5
 * Time: 45:07
 */
import java.util.*;
import java.io.*;
public class taming {
	public static void main(String[] args) throws IOException{
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("taming.in"));
		int N = scan.nextInt();
		int[] days = new int[N];
		for(int i = 0; i < N; i++) {
			days[i] = scan.nextInt();
		}
		scan.close();
		
		int M = 1;
		int prev = -1;
		for(int i = 1; i < N; i++) {
			if(days[i] != -1 && days[i] != 0) {
				int known = days[i];
				if(days[i-known] == -1 && i-known != prev) {
					for(int j = 1; j <= i-known; j++) {
						if(days[j] == -1) {
							M++;
						}
					}
					prev = i-known;
				}
			} else if(days[i] == 0) {
				M++;
			}
		}
		
		int m = 1;
		prev = -1;
		for(int i = 1; i < N; i++) {
			if(days[i] != -1 && days[i] != 0) {
				int known = days[i];
				if(days[i-known] == -1 && i-known != prev) {
					m++;
					prev = i-known;
				}
			} else if(days[i] == 0) {
				m++;
			}
		}
		
		String output = m + " " + M;
//		System.out.println(output);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("taming.out")));
		out.println(output);
		out.close();
	}
}
