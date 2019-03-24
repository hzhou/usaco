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
TASK: planting
 */

public class planting {
	static int n;
	static ArrayList<Integer>[] graph;
	public static void main(String[] args) throws IOException{
//		Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\planting.in.txt"));
//		FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\planting.out.txt"));
		Scanner input = new Scanner(new File("planting.in"));
		FileWriter fileWriter = new FileWriter(new File("planting.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		n = input.nextInt();
		//goes from 1 to n, 0 is always false
		/*
		boolean[][] graph = new boolean[n+1][n+1];
		for(int i=0; i<n-1; i++) {
			int x = input.nextInt();
			int y = input.nextInt();
			graph[x][y] = true;
			graph[y][x] = true;
		}		
		/**/
		
		graph = new ArrayList[n+1];
		for(int i=1; i<=n; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for(int i=0; i<n-1; i++) {
			int field1 = input.nextInt();
			int field2 = input.nextInt();
			graph[field1].add(field2);
			graph[field2].add(field1);
			
		}
		
		//find longest distance
		//i is beginning
		
		int longestLength = Integer.MIN_VALUE;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int length = DFS(i, j, graph.clone());
				if(length > longestLength)
					longestLength = length;
			}
		}
		
		printWriter.println(n - longestLength + 2);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	
	private static int DFS(int startingPos, int targetPos, ArrayList[] graph) {
		int result = 1;
		if(graph[startingPos].isEmpty()) {
			return 0;
		}
		else if(graph[startingPos].contains(targetPos)) {
			return 1;
		}
		else {
			//visited.add(startingPos);
			removeConnections(graph, startingPos);
			for(int i=0; i<graph[startingPos].size(); i++) {
				//if(!visited.contains(graph[startingPos].get(i)))
					result += DFS((int)graph[startingPos].get(i), targetPos, graph.clone());
			}
		}
		return result;
	}
	
	//prevents infinite loops
	private static void removeConnections(ArrayList[] graph, int remove) {
		for(int i=1; i<graph.length; i++) {
			if(i != remove) {
				for(int j=0; j<graph[i].size(); j++) {
					if((int)graph[i].get(j) == remove) {
						graph[i].remove(j);
					}
				}
			}
		}
	}
	
}