//Jasmine Zhang
//All cases passed in 1 hour and 30 minutes 
//Spent another hour compressing code
import java.util.*;
import java.io.*;
public class reduce {
	static int n;
	static int [] x;
	static int [] y;
	static Integer [] pX;
	static Integer [] pY;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("reduce.in"));
		n = scan.nextInt();
		
		x = new int [n];
		y = new int [n];
		pX = new Integer [n];
		pY = new Integer [n];
		for (int i = 0; i < n; i++) {
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
			pX[i] = i;
			pY[i] = i;
		}
		
		Arrays.sort(pX, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return x[i1] - x[i2];
			}
		});
		Arrays.sort(pY, new Comparator <Integer> () {
			public int compare (Integer i1, Integer i2) {
				return y[i1] - y[i2];
			}
		});
		
		for (int i = 0; i < n; i++) {
			System.out.println(x[pX[i]] + " " + y[pX[i]]); 
		}
		for (int i = 0; i < n; i++) {
			System.out.println(x[pY[i]] + " " + y[pY[i]]); 
		}
		
		int xMin = x[pX[0]];
		int xMax = x[pX[n-1]];
		int yMin = y[pY[0]];
		int yMax = y[pY[n-1]];
		int minArea = findArea(xMin, xMax, yMin, yMax);
		
	
		if (minArea != 0) {
			
			for (int i = 0; i < 3; i++) {
				int x2y1 = remove2X1Y(new int [] {i, n-3+i, 0, n-1});
				int y2x1 = remove2Y1X(new int [] {0, n-1, i, n-3+i});
				if (Math.min(x2y1, y2x1) < minArea)
					minArea = Math.min(x2y1, y2x1);
			}
			for (int i = 0; i < 4; i++ )
			{
				int allX = useAllX(new int [] {i, n-4+i, 0, n-1});
				int allY = useAllY(new int [] {0, n-1, i, n-4+i});
				
				if (Math.min(allX, allY) < minArea)
					minArea = Math.min(allX, allY);
				
			}
			
		
			
			
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")));
		System.out.println(minArea + "s");
		out.println(minArea);
	
		out.close();
		scan.close();
	}
	public static void reviseBoundX (int [] bound) {
		HashSet <Integer> ycoord = new HashSet <Integer> ();
		
		for (int i = 0; i < bound[0]; i++) 
			ycoord.add(y[pX[i]]);
		
		for (int i = n-1; i > bound[1]; i--) 
			ycoord.add(y[pX[i]]);
		
		int in = 0;
		int min = y[pY[in]];
		while (ycoord.contains(min)) {
			bound[2]++;
			in++;
			min = y[pY[in]];
		}
		in = n-1;
		int max = y[pY[in]];
		while (ycoord.contains(max)) {
			bound[3]--;
			in--;
			max = y[pY[in]];
		}
		
	}
	
	public static int useAllX (int [] bound) {
		
		reviseBoundX(bound);
		return findArea(bound);
	}
	
	
	public static void reviseBoundY (int [] bound) {
		HashSet <Integer> xcoord = new HashSet <Integer> ();
		for (int i = 0; i < bound[2]; i++) 
			xcoord.add(x[pY[i]]);
		
		for (int i = n-1; i > bound[3]; i--) 
			xcoord.add(x[pY[i]]);
		int in = 0;
		int min = x[pX[in]];
		while (xcoord.contains(min)) {
			bound[0]++;
			in++;
			min = x[pX[in]];
		}
		in = n-1;
		int max = x[pX[in]];
		while (xcoord.contains(max)) {
			bound[1]--;
			in--;
			max = x[pX[in]];
		}
		
	}
	
	public static int useAllY (int [] bound) {
		reviseBoundY(bound);
		return findArea(bound);
		
	}
	
	public static int remove2X1Y (int [] bound) {
		reviseBoundX(bound);
		bound[2]++;
		System.out.println(Arrays.toString(bound));
		
		int first = findArea(bound);
		
		
		bound[2] = 0;
		bound[3] = n-1;
		reviseBoundX(bound);
		bound[3]--;
		System.out.println(Arrays.toString(bound));
		int second = findArea(bound);

		return Math.min(first, second);
	}
	public static int remove2Y1X (int [] bound) {
	
		reviseBoundY(bound);
		bound[0]++;
		
		int first = findArea(bound);
		
		bound[0] = 0;
		reviseBoundY(bound);
		bound[1]--;
		
		int second = findArea(bound);
		return Math.min(first, second);
	}
	
	
	public static int findArea (int xMin, int xMax, int yMin, int yMax) {
		return (xMax-xMin)*(yMax-yMin);
	}
	public static int findArea (int [] bound) {
		
		return (x[pX[bound[1]]]-x[pX[bound[0]]])*(y[pY[bound[3]]]-y[pY[bound[2]]]);
	}
	

}
