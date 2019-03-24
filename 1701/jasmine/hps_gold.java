//Jasmine Zhang
//1 hour 30 minutes
//Tried to recursively simulate all possibilities, but got too complicated
//Gave up after an hour and looked at answer
//All cases passed

import java.util.*;
import java.io.*;
public class hps {

	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("hps.in"));
		int n = scan.nextInt();
		int k = scan.nextInt();
		
		//moves that win against farmer john's moves
		int [] farm = new int [n];
		for (int i = 0; i < n; i++) {
			String m = scan.next();
			if (m.equals("H"))
				farm[i] = 0;
			else if (m.equals("P"))
				farm[i] = 1;
			else if (m.equals("S"))
				farm[i] = 2;
			//System,out.or
		}
		//System.out.println(Arrays.toString(farm));
		
		//only n*k*3 states
		//[n moves][k switches][3 possible moves]
		//start with one farmer move and build up 
		int dp [][][] = new int [n+1][k+1][3];
		
		//n moves
		for (int i = 0; i <= n; i++) {
			//how many switches
			for (int j = 0; j <= k; j++) {
				//each state
				for (int m = 0; m < 3; m++) {
					//base case
					if (i == 0) {
						dp[i][j][m] = 0;
					}
					else {
						
						int add = 0;
						//always adds one if the current state beats farmer john
						if (m == farm[i-1])
							add = 1;
						//no change in move
						if (j == 0) 
							dp[i][j][m] = dp[i-1][j][m]+add;
						else {
							//two possible moves that bessie could have switched from to
							int switch1 = (m+1)%3;
							int switch2 = (m+2)%3;
							
							//takes the max of the changing to a different state and staying at the same state
							//reduces the number of possible states
							dp[i][j][m] = Math.max(Math.max(dp[i-1][j-1][switch1], dp[i-1][j-1][switch2]),dp[i-1][j][m]);
							dp[i][j][m] += add;
							
							
						}
						
					}
					//System.out.println(dp[i][j][m] + " " + i + " " + j + " " + m);
				}
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hps.out")));
		System.out.println(Math.max(Math.max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]));
		out.println(Math.max(Math.max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]));
	
		out.close();
		scan.close();
	}

}
