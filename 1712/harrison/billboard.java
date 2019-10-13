// package com.bronze.dec2017;

/*
 * Harrison Zhang
 * Tests passed: 1, 2, 5, 6, 7, 8, 9
 * Time: more than an hour
 */
import java.util.*;
import java.io.*;
public class billboard {
	public static void main(String[] args) throws IOException{
//		Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("billboard.in"));
		int x1_1 = scan.nextInt();
		int y1_1 = scan.nextInt();
		int x2_1 = scan.nextInt();
		int y2_1 = scan.nextInt();
		
		int x1_2 = scan.nextInt();
		int y1_2 = scan.nextInt();
		int x2_2 = scan.nextInt();
		int y2_2 = scan.nextInt();
		
		int x1_b = scan.nextInt();
		int y1_b = scan.nextInt();
		int x2_b = scan.nextInt();
		int y2_b = scan.nextInt();
		scan.close();
		
		int minusX1_1 = 0, minusY1_1 = 0;
		int minusX;
		int minusX2_1 = 0, minusY2_1 = 0;
		int minusY;
		
		if(x1_1 < x1_b) {
			minusX1_1 = x1_b;
		} else {
			minusX1_1 = x1_1;
		}
		if(x2_1 < x2_b){
			minusX2_1 = x2_1;
		} else {
			minusX2_1 = x2_b;
		}
		
		
		if(y1_1 < y1_b) {
			minusY1_1 = y1_b;
		} else {
			minusY1_1 = y1_1;
		}
		if(y2_1 < y2_b){
			minusY2_1 = y2_1;
		} else {
			minusY2_1 = y2_b;
		}
		
		minusX = minusX2_1 - minusX1_1;
		minusY = minusY2_1 - minusY1_1;
		int minusArea1 = (minusX) * (minusY);
		int area1 = (x2_1 - x1_1) * (y2_1 - y1_1);
		int newArea1 = area1 - minusArea1;
		
		if(x1_2 < x1_b) {
			minusX1_1 = x1_b;
		} else {
			minusX1_1 = x1_2;
		}
		if(x2_2 < x2_b){
			minusX2_1 = x2_2;
		} else {
			minusX2_1 = x2_b;
		}
		
		
		if(y1_2 < y1_b) {
			minusY1_1 = y1_b;
		} else {
			minusY1_1 = y1_2;
		}
		if(y2_2 < y2_b){
			minusY2_1 = y2_2;
		} else {
			minusY2_1 = y2_b;
		}
		
		minusX = minusX2_1 - minusX1_1;
		minusY = minusY2_1 - minusY1_1;
		int minusArea2 = (minusX) * (minusY);
		int area2 = (x2_2 - x1_2) * (y2_2 - y1_2);
		int newArea2 = area2 - minusArea2;
		
		System.out.println(newArea1 + newArea2);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
		out.println(newArea1 + newArea2);
		out.close();
		
	}
}
