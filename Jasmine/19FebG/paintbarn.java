import java.util.*;
import java.io.*;
public class paintbarn {
	
	static int [][] barn = new int [200][200];
	static int k;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("paintbarn.in"));
		int n = scan.nextInt();
		k = scan.nextInt();
		
		for (int i = 0; i < n; i++) {
			int x1 = scan.nextInt();
			int y1 = scan.nextInt();
			int x2 = scan.nextInt();
			int y2 = scan.nextInt();
			for (int a = x1; a < x2; a++) {
				for (int b = y1; b < y2; b++) {
					barn[a][b]++;
					
				}
			}
			
		}
		
		
		boolean canPaint = false;
		int x1 = -1;
		int x2 = -1;
		int y1 = -1;
		int y2 = -1;
		int total = 0;
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				int num = barn[i][j];
				//System.out.println(num);
				if (num != k && num != k-1) {
					continue;
				}
				//System.out.println(num);
				if (num == k) {
					total++;
					continue;
				}
				if (!canPaint) {
					//careful with x and i and y and j
					x1 = i;
					x2 = i+1;
					y1 = j;
					y2 = j+1;
					canPaint = true;
				}
				else {
					if (i < x1)
						x1 = i;
					else if (i+1 > x2)
						x2 = i+1;
					
					if (j < y1)
						y1 = j;
					else if (j+1 > y2)
						y2 = j+1;
					
				}
			}
		}
		
		
		int Uleft = 0;
		int Lright = 0;
		ArrayList <Rectangle> rect = new ArrayList <Rectangle> ();
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				for (int a = i+1; a <= x2; a++) {
					for (int b = j+1; b <= y2; b++) {
						Rectangle r = new Rectangle (i,j,a,b);
						int add = add(r);
						if (add <= 0)
							continue;
						
						r.setSize(add);
						//System.out.println(r);
						rect.add(r);
					}
				}
			}
		}
		Collections.sort(rect);
		
		total += rect.get(0).size;
		int i = 1;
		while (i < rect.size()) {
			if (!overlap(rect.get(0),rect.get(i))) {
				total += rect.get(i).size;
				break;
			}
			i++;
		}
		
		System.out.println(x1 + " " + x2);
		System.out.println(y1 + " " + y2);
		System.out.println(total);
		//System.out.println(rect);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("paintbarn.out")));
		out.println(total);
	
		out.close();
		scan.close();
	}
	public static boolean overlap (Rectangle r1, Rectangle r2) {
		int x1 = Math.max(r1.x1, r2.x1);
		int x2 = Math.min(r1.x2, r2.x2);
		int y1 = Math.max(r1.y1, r2.y1);
		int y2 = Math.min(r1.y2, r2.y2);
		if ((y2-y1) *(x2-x1) > 0)
			return false;
		return true;
	}
	public static int add (Rectangle r) {
		int sum = 0;
		for (int i = r.x1; i < r.x2; i++) {
			for (int j = r.y1; j < r.y2; j++) {
				if (barn[i][j] == k-1)
					sum++;
				else if (barn[i][j] == k)
					sum--;
			}
		}
		return sum;
	}

}
class Rectangle implements Comparable{
	int x1;
	int y1;
	int x2;
	int y2;
	int size = 0;
	Rectangle (int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}
	public void setSize (int s) {
		size = s;
	}
	@Override
	public int compareTo(Object o) {
		Rectangle r = (Rectangle)(o);
		// TODO Auto-generated method stub
		return r.size - size;
	}
	public String toString () {
		String s = x1 + "-" + y1 + " ";
		s+= x2 + "-" + y2+ " ";
		s+= "" + size;
		return s;
	}
}
