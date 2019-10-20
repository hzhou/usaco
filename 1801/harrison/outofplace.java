package com.bronze.jan2018;

/*
 * Harrison Zhang
 * Tests Passed: 1,2,3,4,6,7,9,10
 * Time: 1:06:17.24
 */

import java.util.*;
import java.io.*;
public class outofplace {
	public static void main(String[] args) throws IOException {
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("outofplace.in"));
		int N = scan.nextInt();
		int order[] = new int[N];
		int sorted[] = new int[N];
		
		for(int i = 0; i < N; i++) {
			int tmp = scan.nextInt();
			order[i] = tmp;
			sorted[i] = tmp;
		}
		scan.close();
		Arrays.sort(sorted);
		
		int prev = order[0];
		int firstNum = 0, step = 0;
		int i = 1;
		while(!Arrays.equals(order, sorted)) {
			if(prev > order[i]) {
				for(int j = i-1; j >= 0 ; j--) {
					if(prev == order[j]) {
						firstNum = j;
					} else if(firstNum == 0){
						firstNum = i-1;
					}
				}
				int tmp = order[i];
				order[i] = order[firstNum];
				order[firstNum] = tmp;
				step ++;
				i = 0;
				firstNum = 0;
			}
			prev = order[i];
			i++;
		}
		
//		System.out.println(step);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(("outofplace.out"))));
		out.println(step);
		out.close();
	}
}
