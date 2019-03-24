package competitionProblems;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: herding
 */

public class herding {
	static int n;
	static int[] locations;
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\herding.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\herding.out.txt"));
		Scanner input = new Scanner(new File("herding.in"));
		FileWriter fileWriter = new FileWriter(new File("herding.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
	
		n = input.nextInt();
		locations = new int[n];
		for(int i=0; i<n; i++) {
			locations[i] = input.nextInt();
		}
		
		Arrays.sort(locations);
		
		printWriter.println(solveMin(locations));
		printWriter.println(solveMax(locations));
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	
	private static int solveMin(int[] arr) {
		int[] temp = arr.clone();
		int result = 0; //for changing the top
		int result2 = 0; //for changing the bottom
		//base case
		if(complete(arr)) {
			return Math.min(result, result2);
		}
		
		//try changing the top
		for(int i=1; i<n-1; i++) {
			if(temp[i+1] - temp[i] > 1) { //two are not adjacent
				result ++;
				for(int j=temp[i]+1; j<temp[i+1]; j++) {
					temp[0] = j;
					Arrays.sort(temp);
					result += solveMin(temp);
				}
			}
		}
		
		temp = arr.clone();
		//try changing the bottom
		for(int i=0; i<n-2; i++) {
			if(temp[i+1] - temp[i] > 1) { //two are not adjacent
				result2 ++;
				for(int j=temp[i]+1; j<temp[i+1]; j++) {
					temp[n-1] = j;
					Arrays.sort(temp);
					result2 += solveMin(temp);
				}
			}
		}
		
		return Math.min(result, result2);
	}
	
	private static int solveMax(int[] arr) {
		int[] temp = arr.clone();
		int result = 0; //for changing the top
		int result2 = 0; //for changing the bottom
		//base case
		if(complete(arr)) {
			return Math.max(result, result2);
		}
		
		//try changing the top
		for(int i=1; i<n-1; i++) {
			if(temp[i+1] - temp[i] > 1) { //two are not adjacent
				result ++;
				for(int j=temp[i]+1; j<temp[i+1]; j++) {
					temp[0] = j;
					Arrays.sort(temp);
					result += solveMax(temp);
				}
			}
		}
		
		temp = arr.clone();
		//try changing the bottom
		for(int i=0; i<n-2; i++) {
			if(temp[i+1] - temp[i] > 1) { //two are not adjacent
				result2 ++;
				for(int j=temp[i]+1; j<temp[i+1]; j++) {
					temp[n-1] = j;
					Arrays.sort(temp);
					result2 += solveMax(temp);
				}
			}
		}
		
		return Math.max(result, result2);
	}
	
	private static boolean complete(int[] arr) {
		for(int i=0; i<arr.length-1; i++) {
			if(arr[i+1] - arr[i] != 1) {
				return false;
			}
		}
		return true;
	}
}