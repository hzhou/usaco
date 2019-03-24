import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: convention
 */

public class convention {
	static int n;
	static int m;
	static int c;
	static int[] arrivalTimes;
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\convention.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\convention.out.txt"));
		Scanner input = new Scanner(new File("convention.in"));
		FileWriter fileWriter = new FileWriter(new File("convention.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		n = input.nextInt();
		m = input.nextInt();
		c = input.nextInt();
		arrivalTimes = new int[n];
		for(int i=0; i<n; i++) {
			arrivalTimes[i] = input.nextInt();
		}
		
		Arrays.sort(arrivalTimes);
//		int max = Integer.MIN_VALUE;
//		for(int i=0; i<n; i+=c) {
//			if(i+c-1 < n) {
//				int temp = Math.abs(arrivalTimes[i]-arrivalTimes[i+c-1]);
//				if(temp > max)
//					max = temp;
//			}
//		}
		
//		int result = backtrack(arrivalTimes, 0);
		
		printWriter.println(binarySearch(0L, 1000000000L));
		//System.out.print(max);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}

//	private int backtrack(int[] arrivalTimes, int k) {
//		if(k >= n) {
//			return 0;
//		}
//		else {
//			k++;
//			
//		}
//	}
	
	//this entire method tests if a specific time works
	private static boolean pos(long wait) {
		int buses = 1;
		int firstArrival = arrivalTimes[0];
		int firstIndex = 0;
		for(int i=1; i<n; i++) {
			if(arrivalTimes[i]-firstArrival > wait ||
			   i + 1 - firstIndex > c) {
				buses++;
				firstArrival = arrivalTimes[i];
				firstIndex = i;
			}
		}
		return buses <= m;
	}
	
	private static long binarySearch(long low, long high) {
		if(low == high) return low; //where the recursion ends
		if(low+1 == high) { //where the recursion ends v2: check each one to see if they work
			if(pos(low)) return low;
			else return high;
		}
		long mid = (low+high)/2;
		if(pos(mid)) return binarySearch(low, mid); //if this time works check if something lower works
		else return binarySearch(mid+1, high); //otherwise check higher for something that does work
	}
	
}
