//Jasmine Zhang
//All cases passed in 1 hour 30 minutes 

import java.util.*;
import java.io.*;
public class countcross {
	//static int [] directions = {1,2,4,8};
	static int n;
	static int [] grid;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("countcross.in"));
		n = scan.nextInt();
		int k = scan.nextInt();
		int r = scan.nextInt();
		
		grid = new int [n*n];
		
		// x |= y ---> x = x | y
		// ex. x = 2, y = 1 
		//  x = 10 | 01  = 11 
		//  x = 3
		// use |= to set the specific bit as true
		
		//for grid index manipulation reference 
		//0 1 2 
		//3 4 5
		//6 7 8   
		int up = 1;
		int right = 2;
		int down = 4;
		int left = 8;
		//up = 1, right = 2; down = 4; left = 8;
		for (int i = 0; i < n; i++) {
			grid[i] |= up; 
			grid[(i+1)*n-1] |= right;
			grid[(n*n)-i-1] |= down; 
			grid[i*n] |= left; 
		}
		
		
		for (int i = 0; i < r; i++) {
			int row1 = scan.nextInt()-1;
			int col1 = scan.nextInt()-1;
			int row2 = scan.nextInt()-1;
			int col2 = scan.nextInt()-1;
			
			if (row1 == row2) {
				if (col1 < col2) {
					grid[row1*n + col1] |= 2;
					grid[row2*n + col2] |= 8;
				}
				else {
					grid[row1*n + col1] |= 8;
					grid[row2*n + col2] |= 2;
				}
			}
			else {
				if (row1 < row2) {
					grid[row1*n + col1] |= 4;
					grid[row2*n + col2] |= 1;
				}
				else {
					grid[row1*n + col1] |= 1;
					grid[row2*n + col2] |= 4;
				}
			}
		}
		
		
		//10000 = has cow
		for (int i = 0; i < k; i++) {
			int row = scan.nextInt()-1;
			int col = scan.nextInt()-1;
			grid[row*n + col] |= 16;
		}
		
		/*
		//System.out.println(1>>1);
		for (int i = 0; i < n*n; i++) {
			System.out.print(Integer.toBinaryString(grid[i]) + " ");
			if ((i+1)% n == 0) 
				System.out.println();
		}
		*/
		
		
		ArrayList <Integer> regions = new ArrayList <Integer> ();
		boolean [] used = new boolean [n*n];
		for (int i = 0; i < n*n; i++) {
			if (used[i])
				continue;
			//System.out.println(i);
			regions.add(DFS(i,used));
		}
		
		int totalCross = 0;
		for (int i = 0; i < regions.size(); i++) {
			for (int j = i+1; j < regions.size(); j++) {
				totalCross += regions.get(i)*regions.get(j);
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("countcross.out")));
		System.out.println(totalCross);
		out.println(totalCross);
	
		out.close();
		scan.close();
	}
	public static int DFS (int in, boolean [] marked) {
		Stack <Integer> stack = new Stack <Integer> ();
		stack.push(in);
		marked[in] = true;
		int cows = 0;
		
		//Up, right, down, left
		int [] add = {-n,1,n,-1};
		
		while (!stack.isEmpty()) {
			int currentIn = stack.pop();
			int num = grid[currentIn];
			for (int i = 0; i < 4; i++, num=num>>1) {
				if ((num&1) == 1 || marked[currentIn + add[i]])
					continue;
				if ((num&1) != 1) {
					stack.push(currentIn + add[i]);
					marked[currentIn+add[i]] = true;
				}
			}
			
			//num = num>>1; don't need to right shift it again
			if (num == 1)
				cows+=1;
			
		}
		return cows;
	}

}
