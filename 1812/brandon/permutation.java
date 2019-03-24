package practiceProblems;

import java.util.ArrayList;
import java.util.Scanner;

public class permutation {
	static int n;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		System.out.println("Enter n (permutes numbers from 1 to n)");
		n = input.nextInt();
		
		//creates an arraylist of numbers left
		ArrayList<Integer> numsLeft = new ArrayList<Integer>();
		for(int i=1; i<=n; i++) {
			numsLeft.add(i);
		}
		
		permute("", numsLeft);
		
		input.close();
	}
	//permute through each possible digit
	private static void permute(String result, ArrayList<Integer> numsLeft) {
		if(result.length() >= n) {
			System.out.println(result);
			return;
		}
		for(int i=0; i<numsLeft.size(); i++) {
			ArrayList<Integer> temp = (ArrayList<Integer>) numsLeft.clone();
			permute(result + temp.remove(i), temp);
		}
	}
}
