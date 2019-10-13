package com.bronze.dec2017;

/*
 * Harrison Zhang
 * i have no clue what im even supposed to do
 */
import java.util.*;
import java.io.*;
public class shuffle {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
//		Scanner scan = new Scanner(new File("shuffle.in"));
		
		int N = scan.nextInt();
		List<Integer> order = new ArrayList<>();
		List<Integer> id = new ArrayList<>();
		List<Integer> newID = new ArrayList<>();
		
		for(int i = 0; i < N; i++) {
			order.add(scan.nextInt());
		}
		
		for(int i = 0; i < N; i++) {
			id.add(scan.nextInt());
		}
		
		scan.close();
		
		int count = 1;
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));
		while(count <= N) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(order.get(i) == i) {
						
					}
				}
				if(count == order.get(i)) {	
					System.out.println(id.get(i));
//					out.println(id.get(i));
				}
			}
			count++;
		}
		out.close();
	}
}
