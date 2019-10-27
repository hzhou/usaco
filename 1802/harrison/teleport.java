// package com.bronze.feb2018;

/*
 * Harrison Zhang
 * Tests passed: 1,3,4,5,6,7,8
 * Time: 35:39
 */
import java.util.*;
import java.io.*;
import java.lang.Math;
public class teleport {
	public static void main(String[] args) throws IOException {
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("teleport.in"));
		int a = scan.nextInt();
		int b = scan.nextInt();
		int x = scan.nextInt();
		int y = scan.nextInt();
		scan.close();
		
		int ans = 0;

		if((Math.abs(a-x) + Math.abs(b-y)) <= (Math.abs(a-y) + Math.abs(b-x))) {
			if((Math.abs(a-x) + Math.abs(b-y)) <= (Math.abs(a-y) + Math.abs(b-y))) {
				if((Math.abs(a-x) + Math.abs(b-y)) <= (Math.abs(a-x) + Math.abs(b-x))) {
					ans = Math.abs(a-x) + Math.abs(b-y);
				} else {
					ans = Math.abs(a-x) + Math.abs(b-x);
				}
			} else {
				ans = Math.abs(a-y) + Math.abs(b-y);
			}
		} else if((Math.abs(a-y) + Math.abs(b-x)) <= (Math.abs(a-x) + Math.abs(b-y))) {
			if((Math.abs(a-y) + Math.abs(b-x)) <= (Math.abs(a-y) + Math.abs(b-y))) {
				if((Math.abs(a-y) + Math.abs(b-x)) <= (Math.abs(a-x) + Math.abs(b-x))) {
					ans = Math.abs(a-y) + Math.abs(b-x);
				} else {
					ans = Math.abs(a-x) + Math.abs(b-x);
				}
			} else {
				ans = Math.abs(a-y) + Math.abs(b-y);
			}
		} else if(Math.abs(x-y) <= (Math.abs(a-x) + Math.abs(b-y))) {
			if(Math.abs(x-y) <= (Math.abs(a-y) + Math.abs(b-x))) {
				ans = Math.abs(x-y);
			} else {
				ans = Math.abs(a-y) + Math.abs(b-x);
			}
		}
		
		
//		System.out.println(ans);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
		out.println(ans);
		out.close();
	}
}
