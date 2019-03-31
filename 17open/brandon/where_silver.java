import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/*
ID: fireblaze
LANG: JAVA
TASK: where
 */

//Name: Brandon Zhang
//10/10 passed
//Time: 3 hours

public class where {
	static char[][] picture;
	static boolean[][] visited;
	//[0] is leftBound, [1] is rightBound, [2] is lowBound, [3] is highBound
	static ArrayList<int[]> PCLs = new ArrayList<int[]>();
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\where.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\where.out.txt"));
		Scanner input = new Scanner(new File("where.in"));
		FileWriter fileWriter = new FileWriter(new File("where.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		int N = input.nextInt();
		input.nextLine();
		picture = new char[N][N];
		for(int i=0; i<N; i++) {
			String temp = input.nextLine();
			picture[i] = temp.toCharArray();
		}
		
		visited = new boolean[N][N];
		
		//loops through the grid
		for(int x1=0; x1<N; x1++) { //left
			for(int y1=0; y1<N; y1++) { //low
				for(int x2=x1; x2<N; x2++) { //right
					for(int y2=y1; y2<N; y2++) { //high
						if(isPCL(x1, x2, y1, y2)) {
							int[] p = {x1, x2, y1, y2};
							PCLs.add(p);
						}
					}
				}
			}
		}
		int result = 0;
		for(int i=0; i<PCLs.size(); i++) {
			if(PCLmaximum(i)) {
				result++;
			}
		}
		
		printWriter.println(result);
		//System.out.print(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	//all this does is rule out regions so they don't get visited again
	private static void floodFill(int x, int y, int value, int leftBound, int rightBound, int highBound, int lowBound) {
		visited[x][y] = true;
		if(x > leftBound && picture[x-1][y] - 'A' == value && !visited[x-1][y]) {
			floodFill(x-1, y, value, leftBound, rightBound, highBound, lowBound);
		}
		if(x < rightBound && picture[x+1][y] - 'A' == value && !visited[x+1][y]) {
			floodFill(x+1, y, value, leftBound, rightBound, highBound, lowBound);
		}
		if(y > lowBound && picture[x][y-1] - 'A' == value && !visited[x][y-1]) {
			floodFill(x, y-1, value, leftBound, rightBound, highBound, lowBound);
		}
		if(y < highBound && picture[x][y+1] - 'A' == value && !visited[x][y+1]) {
			floodFill(x, y+1, value, leftBound, rightBound, highBound, lowBound);
		}
	}
	private static boolean isPCL(int leftBound, int rightBound, int lowBound, int highBound) {
		int numOfColors = 0;
		int[] colors = new int[26];
		//resets the visited array for the area its going to check
		for(int i=leftBound; i<=rightBound; i++) {
			for(int j=lowBound; j<=highBound; j++) {
				visited[i][j] = false;
			}
		}
		//flood fills through and counts the different regions' colors
		for(int i=leftBound; i<=rightBound; i++) {
			for(int j=lowBound; j<=highBound; j++) {
				if(!visited[i][j]) {
					int color = picture[i][j] - 'A';
					if(colors[color] == 0) numOfColors++;
					colors[color]++;
					floodFill(i, j, color, leftBound, rightBound, highBound, lowBound);
				}
			}
		}
		if(numOfColors != 2) return false; //if there aren't two colors in the region it's automatically ruled out
		boolean foundone = false, foundmany = false;
		for(int i=0; i<26; i++) {
			if(colors[i] == 1) foundone = true; //if it finds one the other if statement will always be false
			if(colors[i] > 1) foundmany = true;
		}
		return foundone && foundmany;
	}
	//checks if i is in j
	private static boolean PCLinPCL(int i, int j) {
		return (PCLs.get(i)[0] >= PCLs.get(j)[0]) && 
				(PCLs.get(i)[1] <= PCLs.get(j)[1]) && 
				(PCLs.get(i)[2] >= PCLs.get(j)[2]) && 
				(PCLs.get(i)[3] <= PCLs.get(j)[3]);	
	}
	//if x is not in any other PCL then it's maximum and it counts
	private static boolean PCLmaximum(int x) {
		for(int i=0; i<PCLs.size(); i++) {
			if(i != x && PCLinPCL(x, i)) {
				return false;
			}
		}
		return true;
	}
}
