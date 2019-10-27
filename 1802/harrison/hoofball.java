package com.bronze.feb2018;

/*
 * Harrison Zhang
 * Tests Passed: none (don't know)
 * Time: 50:55.77
 */
import java.util.*;
import java.io.*;
import java.lang.Math;
public class hoofball {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int[] cow = new int[N];
		int[] sorted = new int[N];
		int[] checker = new int[N];
		for(int i = 0; i < N; i++) {
			int tmp = scan.nextInt();
			cow[i] = tmp;
			sorted[i] = tmp;
		}
		scan.close();
		Arrays.sort(sorted);
		
		int pass = 0;
		int count = 0;
		while(checker != sorted) {
			int posPass = 1000;
			int start = cow[0];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					pass = cow[j];
					if(Math.abs(pass-start) < posPass && pass != start) {
						posPass = Math.abs(pass-start);
					}
					count++;
				}
				checker[count] = pass;
				start = pass;
				count = 0;
			}
			Arrays.sort(checker);
			break;
		}
		
		System.out.println(Arrays.toString(checker));
		
	}
}
