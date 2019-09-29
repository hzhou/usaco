package com.bronze.feb2019;
/*
 * Harrison Zhang
 * Tests passed: 1, 2
 */
import java.util.*;
import java.io.*;
import java.lang.Math;
public class herding {
	public static void main(String[] args) throws Exception{
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("herding.in"));
		String input = scan.nextLine();
		scan.close();
		
		StringTokenizer st = new StringTokenizer(input);
		int spot1 = Integer.valueOf(st.nextToken());
		int spot2 = Integer.valueOf(st.nextToken());
		int spot3 = Integer.valueOf(st.nextToken());
		int answerMin = 0;
		int answerMax = 0;
		
		//min
		if(Math.abs(spot1-spot2) == 2 || Math.abs(spot1-spot3) == 2 || Math.abs(spot2-spot3) == 2) {
			if(Math.abs(spot1-spot2) == Math.abs(spot2-spot3) || Math.abs(spot1-spot2) == Math.abs(spot1-spot3)) {
				answerMin = 0;
			} else {
				answerMin += 1;
			}
		}
		else if(Math.abs(spot1-spot2) > 2 && Math.abs(spot1-spot3) > 2 && Math.abs(spot2-spot3) > 2) {
			answerMin += 2;
		}
				
		//max
		if(Math.abs(spot1-spot2) == 2 || Math.abs(spot1-spot3) == 2 || Math.abs(spot2-spot3) == 2) {
			if(Math.abs(spot1-spot2) == Math.abs(spot2-spot3) || Math.abs(spot1-spot2) == Math.abs(spot1-spot3)) {
				answerMax = 0;
			} else {
				answerMax += 2;
			}
		}
		else if(Math.abs(spot1-spot2) > 2 && Math.abs(spot1-spot3) > 2 && Math.abs(spot2-spot3) > 2) {
			answerMax += 2;
		}
		
//		System.out.println(answerMin + "\n" + answerMax);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("herding.out")));
		out.println(answerMin + "\n" + answerMax);
		out.close();
		
	}
}
