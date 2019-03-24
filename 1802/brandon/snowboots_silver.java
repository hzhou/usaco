import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
//import java.util.ArrayList;
//import java.util.LinkedList;
//import java.util.Queue;

/*
ID: fireblaze
LANG: JAVA
TASK: snowboots
 */

//Name: Brandon Zhang
//Time: 2 hours
//10/10 passed

public class snowboots {
	//static Queue<Boots> bag;
	static int N;
	static int B;
	static int[] path;
	static Boots[] bag;
	static int result = Integer.MAX_VALUE;
	static boolean[][] visited = new boolean[250][250];
	public static void main(String[] args) throws IOException{
		//Scanner input = new Scanner(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\snowboots.in.txt"));
		//FileWriter fileWriter = new FileWriter(new File("C:\\Users\\fireb\\Dropbox\\Brandon\\workspace\\snowboots.out.txt"));
		Scanner input = new Scanner(new File("snowboots.in"));
		FileWriter fileWriter = new FileWriter(new File("snowboots.out"));
		PrintWriter printWriter = new PrintWriter(fileWriter, false);
		
		N = input.nextInt();
		B = input.nextInt();
		path = new int[N];
		for(int i=0; i<N; i++)
			path[i] = input.nextInt();
		bag = new Boots[B];
		for(int i=0; i<B; i++) {
			int s = input.nextInt();
			int m = input.nextInt();
			bag[i] = new snowboots.Boots(s, m);
		}
		
		solve(0, 0);
		
		//System.out.println(solve());
		printWriter.println(result);
		
		printWriter.close();
		fileWriter.close();
		input.close();
	}
	private static void solve(int index, int boots) {
		if(visited[index][boots]) { //if this combination was already reached, prevents infinite loops
			return;
		}
		visited[index][boots] = true;
		
		if(index == N-1) { //then he did make it, record how many boots were used
			result = Math.min(result, boots);
			return;
		}
		
		//try all possible steps forward
		for(int i=index+1; i<N && i - index <= bag[boots].maxStep; i++) {
			if(path[i] <= bag[boots].snowDepth) {
				solve(i, boots); //moves forward specified amount
			}
		}
		
		//try all possible boot switches
		for(int i=boots+1; i<B; i++) {
			if(path[index] <= bag[i].snowDepth) {
				solve(index, i); //switches boots without moving
			}
		}
	}
	private static class Boots{
		int snowDepth;
		int maxStep;
		public Boots(int s, int m) {
			snowDepth = s;
			maxStep = m;
		}
	}
}
