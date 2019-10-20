package com.bronze.jan2018;

/*
 * Harrison Zhang
 * Test Passed
 * Time: 
 */

import java.util.*;
import java.io.*;
public class lifeguards {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		List<Integer> start = new ArrayList<>();
		List<Integer> end = new ArrayList<>();
		List<Integer> posStart = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			start.add(scan.nextInt());
			end.add(scan.nextInt());
		}
		scan.close();
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(start.get(j) < start.get(i)) {
					posStart.add(start.get(j));
				} else {
					posStart.add(-1);
				}
				if(end.get(j) > end.get(i)) {
					
				}
			}
		}
	}
}
