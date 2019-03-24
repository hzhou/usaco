import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: mooyomooyo
 */

public class mooyomooyo {
	static int[][] grid;
	static int n;
	static int k;
	static boolean[][] visitedArray;
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\mooyomooyo.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\mooyomooyo.out.txt"));
		Scanner input = new Scanner(new File("mooyomooyo.in"));
		FileWriter fileWriter = new FileWriter(new File("mooyomooyo.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		n = input.nextInt();
		k = input.nextInt();
		grid = new int[n][10];
		input.nextLine();
		for(int i=0; i<n; i++) {
			String[] temp = input.nextLine().split("");
			for(int j=0; j<10; j++) {
				grid[i][j] = Integer.parseInt(temp[j]);
			}
		}
		
		boolean foundone = true;
		while(foundone) {
			visitedArray = new boolean[n][10]; //visitedArray tracks the found regions in the flood fill
			//creates a list of the distinct regions and their attributes
			ArrayList<int[]> regions = new ArrayList<int[]>();
			for(int x=0; x<n; x++) {
				for(int y=0; y<10; y++){
					if(!visitedArray[x][y] && grid[x][y] != 0) {
						//flood fills through the thing
						int area = floodFill(x, y, grid[x][y], boolClone());
						
						//inserts
						int[] temp = {area, grid[x][y], x, y};
						regions.add(temp);
					}
				}
			}
	
			foundone = false;
			//finds all the areas with more than 3 and removes them
			visitedArray = new boolean[n][10];
			for(int i=0; i<regions.size(); i++) {
				if(regions.get(i)[0] >= k) {
					foundone = true;
					floodRemove(regions.get(i)[2], regions.get(i)[3], regions.get(i)[1], boolClone());
				}
			}
			if(!foundone)
				break;
			
			gravity();
//			for(int i=0; i<n; i++) {
//				for(int j=0; j<10; j++) {
//					System.out.print(grid[i][j]);
//				}
//				System.out.println();
//			}
//			System.out.println("\n");
		}
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<10; j++) {
				printWriter.print(grid[i][j]);
			}
			printWriter.println();
		}
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}

	private static int floodFill(int x, int y, int value, boolean[][] visited) {
		int temp = 0;
		visited[x][y] = true;
		if(grid[x][y] == value) {
			temp++;
			visitedArray[x][y] = true;
			if(x > 0 && !visited[x-1][y]) 
				temp += floodFill(x-1, y, value, visited);
			if(y > 0 && !visited[x][y-1])
				temp += floodFill(x, y-1, value, visited);
			if(x < n-1 && !visited[x+1][y])
				temp += floodFill(x+1, y, value, visited);
			if(y < 9 && !visited[x][y+1])
				temp += floodFill(x, y+1, value, visited);
		}
		return temp;
	}
	
	private static void floodRemove(int x, int y, int value, boolean[][] visited) {
		visited[x][y] = true;
		if(grid[x][y] == value) {
			grid[x][y] = 0;
			if(x > 0 && !visited[x-1][y]) 
				floodRemove(x-1, y, value, visited);
			if(y > 0 && !visited[x][y-1])
				floodRemove(x, y-1, value, visited);
			if(x < n-1 && !visited[x+1][y])
				floodRemove(x+1, y, value, visited);
			if(y < 9 && !visited[x][y+1])
				floodRemove(x, y+1, value, visited);
		}
	}
	
	private static void gravity() {
		for(int i=n-1; i>=0; i--) { //goes through the rows bottom up
			for(int j=0; j<10; j++) { //goes through each individual column
//				if(grid[i-1][j] == 0) { //moves the tile down if it has blank space beneath
//					grid[i-1][j] = grid[i][j];
//					grid[i][j] = 0;
//				}
				boolean isEmpty = isColumnEmpty(i, j);
				while(!isEmpty && grid[i][j] == 0) { //if the current tile is blank space
					for(int k=i-1; k>=0; k--) { //move every tile above it down by one
						grid[k+1][j] = grid[k][j];
						grid[k][j] = 0;
					}
				}
			}
		}
	}
	
	private static boolean[][] boolClone(){
		boolean[][] result = new boolean[n][n];
		for(int i=0; i<n; i++) {
			result[i] = visitedArray[i].clone();
		}
		return result;
	}
	
	private static boolean isColumnEmpty(int row, int col) {
		for(int i=0; i<row; i++) {
			if(grid[i][col] != 0)
				return false;
		}
		return true;
	}
}
