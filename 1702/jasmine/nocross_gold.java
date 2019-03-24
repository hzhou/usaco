//Jasmine Zhang
//Dynamic Programming 
//1 hour 30 minutes
//Had to look at answer
import java.util.*;
import java.io.*;
public class nocross {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("nocross.in"));
		int n = scan.nextInt();
		
		int [] left = new int [n];
		for (int i = 0; i < n; i++)
			left[i] = scan.nextInt();
		
		int [] right = new int [n];
		for (int i = 0; i < n; i++) 
			right[i] = scan.nextInt();
		
		//System.ou
		
		//[fields on the left][fields on the right] = max number of cross walks with that many fields
		int [][] dp = new int [n][n];
		  
		//base case
		//if only two fields, then it's one if the crosswalk can be drawn, zero if not 
		dp[0][0] = crosswalk(left[0],right[0]);
		
		//get other base cases, which means there's only one field on one side
		//meaning there can be at most one crosswalk
		for (int i = 1; i < n; i++) {
			dp[i][0] = Math.max(dp[i-1][0], crosswalk(left[i],right[0]));
			dp[0][i] = Math.max(dp[0][i-1], crosswalk(left[0],right[i]));
		}
		
		
		//With each combination of number of fields on each side, you can either draw a cross walk with 
		//the field or not use it at all, 
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				 					//not use either field                          //draw cross walk between these 2 fields
				dp[i][j] = Math.max(Math.max(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1] + crosswalk(left[i],right[j]));
				
				
			}
		}
		
		
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("nocross.out")));
		out.println(dp[n-1][n-1]);
		System.out.println(dp[n-1][n-1]);
		
		
	
		out.close();
		scan.close();
	}
	public static int crosswalk (int a, int b) {
		if (Math.abs(a-b) <= 4)
				return 1;
		return 0;
	}

}
