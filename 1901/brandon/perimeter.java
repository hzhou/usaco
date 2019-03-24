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
TASK: perimeter
 */

public class perimeter {
	static int n;
	static String[][] grid;
	static boolean[][] visitedArray;
	static boolean[][] visitedArray2;
	public static void main(String[] args) throws IOException{
//		Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\perimeter.in.txt"));
//		FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\perimeter.out.txt"));
		Scanner input = new Scanner(new File("perimeter.in"));
		FileWriter fileWriter = new FileWriter(new File("perimeter.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		n = input.nextInt();
		input.nextLine();
		grid = new String[n][n];
		for(int i=0; i<n; i++) {
			String[] temp = input.nextLine().split("");
			for(int j=0; j<n; j++) {
				grid[i][j] = temp[j];
			}
		}
		
		/*
		visitedArray = new boolean[n][n];
		System.out.println(findArea(0, 0, boolClone()));
		visitedArray = new boolean[n][n];
		System.out.println(findPerimeter(0, 0, boolClone()));
		
		/**/
		visitedArray = new boolean[n][n]; //visitedArray tracks the found regions in the flood fill
		visitedArray2 = new boolean[n][n];
		//creates a list of the distinct regions and their attributes
		ArrayList<int[]> regions = new ArrayList<int[]>();
		for(int x=0; x<n; x++) {
			for(int y=0; y<n; y++){
				if(!visitedArray[x][y] && grid[x][y].equals("#")) {
					//flood fills through the thing
					int area = findArea(x, y, boolClone());
					int perimeter = findPerimeter(x, y, boolClone2());
					
					//inserts
					int[] temp = {area, perimeter};
					regions.add(temp);
				}
			}
		}
		/**/
		
		Collections.sort(regions, new Comparator<int[]>() { 
	          @Override              
	          public int compare(final int[] entry1,  
	                             final int[] entry2) { 
	  
	            // To sort in descending order revert  
	            // the '>' Operator 
	            if (entry1[0] > entry2[0]) 
	                return -1; 
	            else if(entry1[0] == entry2[0]) {
	            	if(entry1[1] < entry2[1]) {
	            		return -1;
	            	}
	            	else {
	            		return 1;
	            	}
	            }
	            else
	                return 1; 
	          } 
	        }); 
		
		printWriter.println(regions.get(0)[0] + " " + regions.get(0)[1]);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	private static int findArea(int x, int y, boolean[][] visited) {
		int temp = 0;
		visited[x][y] = true;
		if(grid[x][y].equals("#")) {
			temp++;
			visitedArray[x][y] = true;
			if(x > 0 && !visited[x-1][y]) 
				temp += findArea(x-1, y, visited);
			if(y > 0 && !visited[x][y-1])
				temp += findArea(x, y-1, visited);
			if(x < n-1 && !visited[x+1][y])
				temp += findArea(x+1, y, visited);
			if(y < n-1 && !visited[x][y+1])
				temp += findArea(x, y+1, visited);
		}
		return temp;
	}
	
	private static int findPerimeter(int x, int y, boolean[][] visited) {
		int temp = 0;
		visited[x][y] = true;
		if(grid[x][y].equals("#")) {
			visitedArray[x][y] = true;
			temp += (4 - numofneighbour(grid, x, y)); 
			if(x > 0 && !visited[x-1][y]) 
				temp += findPerimeter(x-1, y, visited);
			if(y > 0 && !visited[x][y-1])
				temp += findPerimeter(x, y-1, visited);
			if(x < n-1 && !visited[x+1][y])
				temp += findPerimeter(x+1, y, visited);
			if(y < n-1 && !visited[x][y+1])
				temp += findPerimeter(x, y+1, visited);
		}
		return temp;
	}
	
	static int numofneighbour(String[][] grid2, int x, int y)  { 
		int count = 0; 
		//checks above
		if (x > 0 && grid2[x - 1][y].equals("#")) 
		count++; 
		
		//checks to the left
		if (y > 0 && grid2[x][y - 1].equals("#")) 
		count++; 
		
		//checks beneath
		if (x < n-1 && grid2[x + 1][y].equals("#")) 
		count++; 
		
		//checks to the right
		if (y < n-1 && grid2[x][y + 1].equals("#")) 
		count++; 
		return count; 
	} 
	
	private static boolean[][] boolClone(){
		boolean[][] result = new boolean[n][n];
		for(int i=0; i<n; i++) {
			result[i] = visitedArray[i].clone();
		}
		return result;
	}
	private static boolean[][] boolClone2(){
		boolean[][] result = new boolean[n][n];
		for(int i=0; i<n; i++) {
			result[i] = visitedArray2[i].clone();
		}
		return result;
	}
}