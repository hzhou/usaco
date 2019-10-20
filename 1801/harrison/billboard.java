package com.bronze.jan2018;

/*
 * Harrison Zhang
 * Tests Passed: all of them
 * Time: 46:08.28
 */

import java.util.*;
import java.io.*;
public class billboard {
	public static void main(String[] args) throws IOException {
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("billboard.in"));
		int lx1 = scan.nextInt();
		int ly1 = scan.nextInt();
		int lx2 = scan.nextInt();
		int ly2 = scan.nextInt();
		
		int bx1 = scan.nextInt();
		int by1 = scan.nextInt();
		int bx2 = scan.nextInt();
		int by2 = scan.nextInt();
		scan.close();
		
		int xSmall, xLarge, ySmall, yLarge;
		if((by1 <= ly1 && by2 >= ly2) && !(bx1 <= lx1 && bx2 >= lx2)) {
			if(bx1 < lx1) {
				xSmall = bx2;
			} else {
				xSmall = lx1;
			}
			if(bx2 > lx2) {
				xLarge = bx1;
			} else {
				xLarge = lx2;
			}
			ySmall = ly1;
			yLarge = ly2;
			
		} else if((bx1 <= lx1 && bx2 >= lx2) && !(by1 <= ly1 && by2 >= ly2)) {
			if(by1 < ly1) {
				ySmall = by2;
			} else {
				ySmall = ly1;
			}
			if(by2 > ly2) {
				yLarge = by1;
			} else {
				yLarge = ly2;
			}
			xSmall = lx1;
			xLarge = lx2;
		} else if((bx1 <= lx1 && bx2 >= lx2) && (by1 <= ly1 && by2 >= ly2)) {
			xSmall = 0;
			xLarge = xSmall;
			ySmall = 0;
			yLarge = ySmall;
		} else {
			xSmall = lx1;
			xLarge = lx2;
			ySmall = ly1;
			yLarge = ly2;
		}
		
		int xNet = xLarge - xSmall;
		int yNet = yLarge - ySmall;
		int area = xNet * yNet;
		
//		System.out.println(area);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
		out.print(area);
		out.close();
	}
}
