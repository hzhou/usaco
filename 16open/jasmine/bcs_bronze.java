//Jasmine Zhang
//1 hour 23 minutes
//Just a lot of code to write and too many variables to keep track

import java.util.*;
import java.io.*;
public class bcs {
	static int n;
	static boolean [][] original;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("bcs.in"));
		n = scan.nextInt();
		int k = scan.nextInt();
		scan.nextLine();
		
		original = new boolean [n][n];
		int total = 0;
		for (int i = 0; i < n; i++) {
			String s = scan.next();
			//make method
			for (int j = 0; j < n; j++) {
				char c = s.charAt(j);
				if (c == '#') {
					original[i][j] = true;
					total++;
				}
			}
		}
		
		ArrayList <Piece> works = new ArrayList <Piece> ();
		for (int i = 0; i < k; i++) {
			
			String [] rows = new String [n];
			String [] cols = new String [n];
			for (int a = 0; a < n; a++) {
				String s = scan.next();
				rows[a] = s;
				//make method
				for (int b = 0; b < n; b++) {
					cols[b] += s.charAt(b);
				}
			}
			
			boolean [][] p = noBord(rows,cols);
			int r = p.length;
			int c = p[0].length;
			/*
			for (int j = 0; j < r; j++) {
				System.out.println(Arrays.toString(p[j]));
			}
			*/
			
			boolean w = true;
			//what part the piece covers
			boolean [] [] part = new boolean [n][n];
			//number of #
			int t = 0;
			for (int a = 0; a < n-r+1; a++) {
				for (int b = 0; b < n-c+1; b++) {
					part = new boolean [n][n];
					int tot = fits(p,part,a,b);
					if (tot != -1) 
						works.add(new Piece (part, tot,i));
					System.out.println(tot);
				}
			}
		}
		
		boolean b = false;
		int id1 = -1;
		int id2 = -1;
		
		for (int i = 0; i < works.size(); i++) {
			for (int j = i+1; j < works.size(); j++) {
				Piece pi1 = works.get(i);
				Piece pi2 = works.get(j);
				for (int a = 0; a < n; a++) {
					System.out.println(Arrays.toString(pi1.p[a]));
				}
				for (int a = 0; a < n; a++) {
					System.out.println(Arrays.toString(pi2.p[a]));
				}
				if (pi1.id == pi2.id || pi1.size+pi2.size != total)
					continue;
				if (ans(pi1.p,pi2.p)) {
					b = true;
					id1 = pi1.id+1;
					id2 = pi2.id+1;
					break;
				}
					
			}
			if (b)
				break;
		}
		
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bcs.out")));
		System.out.println(Math.min(id1, id2) + " " + Math.max(id1, id2));
		out.println(Math.min(id1, id2) + " " + Math.max(id1, id2));
	
		out.close();
		scan.close();
	}
	public static boolean ans (boolean [][] p1, boolean [][] p2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (p1[i][j] && p2[i][j])
					return false;
			}
		}
		return true;
	}
	
	public static int fits (boolean[][] piece, boolean [][] part, int a, int b) {
		int total = 0;
		for (int i = 0; i < piece.length; i++){
			for (int j = 0; j < piece[0].length; j++) {
				if(piece[i][j] && !original[i+a][j+b]) {
					//System.out.println(i + " " + j);
					return -1;
				}
				if (piece[i][j] && original[i+a][j+b]) {
					part[i+a][j+b] = true;
					total++;
					System.out.println((i+a) + " " + (j+b));
				}
			}
				
		}
		return total;
	}
	
	public static boolean [][] noBord (String [] rows, String [] cols) {
		boolean [] empRow  = new boolean[n];
		boolean [] empCol  = new boolean[n];
		int newR = n;
		int newC = n;
		
		int in = 0;
		while (in < n && !rows[in].contains("#")) {
			empRow[in] = true;
			in++;
			newR--;
		}
		in = n-1;
		while (in >= 0 && !rows[in].contains("#")) {
			empRow[in] = true;
			in--;
			newR--;
		}
		
		in = 0;
		while (in < n && !cols[in].contains("#")) {
			empCol[in] = true;
			in++;
			newC--;
		}
		in = n-1;
		while (in >= 0 && !cols[in].contains("#")) {
			empCol[in] = true;
			in--;
			newC--;
		}
		
		boolean [][] p = new boolean [newR][newC];
		int r = 0;
		for (int a = 0; a < n; a++) {
			if (empRow[a])
				continue;
			String s = rows[a];
			int c = 0;
			for (int b = 0; b < n; b++) {
				if (empCol[b])
					continue;
				char ch = s.charAt(b);
				if (ch == '#')
					p[r][c] = true;
				c++;
			}
			r++;
			
		}
		return p;
	}
	
	
	

}
class Piece {
	boolean [][] p;
	int size;
	int id;
	Piece (boolean [][] p, int s, int i) {
		this.p = p;
		size = s;
		id = i;
	}
}
