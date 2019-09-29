//package com.bronze.feb2019;
/*
 * Harrison Zhang
 * 2 hrs
 * Test Passed: 1
 */
import java.util.*;
import java.io.*;
public class traffic {
	public static void main(String[] args) throws IOException{
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("traffic.in"));
		int N = Integer.valueOf(scan.nextLine());
		
		List<String> list = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			list.add(scan.nextLine());
		}
		
		scan.close();
		
		StringTokenizer st1 = new StringTokenizer(list.get(0));
		String part1_1 = st1.nextToken();
		int part2_1 = Integer.valueOf(st1.nextToken());
		int part3_1 = Integer.valueOf(st1.nextToken());
		
		StringTokenizer st2 = new StringTokenizer(list.get(1));
		String part1_2 = st2.nextToken();
		int part2_2 = Integer.valueOf(st2.nextToken());
		int part3_2 = Integer.valueOf(st2.nextToken());
		
		int upper1 = part3_2;
		int lower1 = part2_2;
		
		if(part1_2.equals("none")) {
			for(int i = 1; i < N; i++) {
				StringTokenizer st3 = new StringTokenizer(list.get(i));
				String TempStr = st3.nextToken();
				int tempNum1 = Integer.valueOf(st3.nextToken());
				int tempNum2 = Integer.valueOf(st3.nextToken());
				if(TempStr.equals("none")) {
					if((upper1 - tempNum2) > 0){
						upper1 -= (upper1 - tempNum2);

					}
					if((tempNum1 - lower1) > 0) {
						lower1 += (tempNum1 - lower1);
					}
				} else {
					break;
				}
			}
		}
		
		if(part1_1.equals("on")) {
			upper1 = upper1 - part3_1;
			lower1 = lower1 - part2_1;
		}
		else if(part1_1.equals("off")) {
			upper1 = upper1 + part3_1;
			lower1 = lower1 + part2_1;
		}
		
//		System.out.println(lower1 + " " + upper1);
		
		String substitute = lower1 + " " + upper1;
		
		for(int i = N-1; i > 0; i++) {
			StringTokenizer st4 = new StringTokenizer(list.get(i));
			String TempStr = st4.nextToken();
			int tempNum1 = Integer.valueOf(st4.nextToken());
			int tempNum2 = Integer.valueOf(st4.nextToken());
			if(TempStr.equals("none")) {
				if((upper1 - tempNum2) > 0){
					upper1 -= (upper1 - tempNum2);

				}
				if((tempNum1 - lower1) > 0) {
					lower1 += (tempNum1 - lower1);
				}
			} else {
				break;
			}
		}
		
		StringTokenizer st5 = new StringTokenizer(list.get(N-1));
		String part1_End = st5.nextToken();
		int part2_End = Integer.valueOf(st5.nextToken());
		int part3_End = Integer.valueOf(st5.nextToken());

		if(part1_End.equals("on")) {
			upper1 = upper1 + part3_End;
			lower1 = lower1 + part2_End;
		}
		else if(part1_End.equals("off")) {
			upper1 = upper1 - (part3_End-part2_End);
			lower1 = lower1 - part2_End;
		}
		
//		System.out.println(lower1 + " " + upper1);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("traffic.out")));
		out.println(substitute);
		out.println(lower1 + " " + upper1);
		out.close();
		
	}
}
