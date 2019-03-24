//Jasmine Zhang
//All cases passed in 35 minutes
import java.util.*;
import java.io.*;
public class art {
	static HashSet <Integer> onTop  = new HashSet <Integer> ();
	static int n;
	static int [][] canvas;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("art.in"));
		
		n = scan.nextInt();
		scan.nextLine();
		
		canvas = new int [n][n];
		for (int i = 0; i < n; i++) {
			String s = scan.nextLine();
			for (int j = 0; j < n; j++) {
				canvas[i][j] = s.charAt(j)-'0';
			}
		}
		
		HashSet <Integer> visColor = new HashSet <Integer> ();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				int num = canvas[i][j];
				if (visColor.contains(num) || num == 0) 
					continue;
				else {
					findRect(num, i, j);
					visColor.add(num);
				}
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("art.out")));
		out.println(visColor.size()-onTop.size());
		
		out.close();
		scan.close();
	}
	
	public static void findRect(int num, int i, int j) {
		int left = j;
		int right = j;
		int up = i;
		int down = i;
		for (int a = 0; a < n; a++){
			for (int b = 0; b < n; b++) {
				if (a == i && b == j)
					continue;
				int num2 = canvas[a][b];
				if (num2 == num) {
					left = Math.min(left, b);
					right = Math.max(right, b);
					up = Math.min(up, a);
					down = Math.max(down, a);
				}
			}
		}
		
		for (int a = up; a <= down; a++) {
			for (int b = left; b <= right; b++) {
				if (canvas[a][b]!= num)
					onTop.add(canvas[a][b]);
			}
		}
	}
	

}
