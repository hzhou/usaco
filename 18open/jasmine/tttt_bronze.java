//Jasmine Zhang
//All cases passed in 15 minutes
import java.util.*;
import java.io.*;
public class tttt {
	static HashSet <Character> one = new HashSet <Character> ();
	static HashSet <Integer> two = new HashSet <Integer> ();
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("tttt.in"));
		
		char [][] board = new char [3][3];
		for (int i = 0; i < 3; i++) {
			String s = scan.next();
			for (int j = 0; j < 3; j++)
				board[i][j] = s.charAt(j);
		}
		
		
		//checking rows and cols
		for (int i = 0; i < 3; i++) {
			line(board[i][0], board[i][1], board[i][2]);
			line(board[0][i], board[1][i], board[2][i]);
		}
		
		//checking diagonals
		line(board[0][0], board[1][1], board[2][2]);
		line(board[0][2], board[1][1], board[2][0]);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tttt.out")));
		out.println(one.size());
		out.println(two.size());
		scan.close();
		out.close();
	}
	public static void line (char c1, char c2, char c3)
	{
		if (c1 == c2 && c2 == c3)
			one.add(c1);
		else if (c1 == c2 || c2 == c3)
			two.add(hash(c1,c3));
		else if (c1 == c3)
			two.add(hash(c1,c2));
			
	}
	public static int hash (char c1, char c2)
	{
		if (c1 < c2)
			return c1*100 + c2;
		return c2*100 + c1;
	}
}
