//Jasmine Zhang
//All cases passed in 20 minutes 
import java.util.*;
import java.io.*;
public class reduce {
	static int [] x;
	static int [] y;
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("reduce.in"));
		int n = scan.nextInt();
		
		x = new int [n];
		y = new int [n];
		Integer [] pX = new Integer [n];
		Integer [] pY = new Integer [n];
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
		
		int xMin = x[pX[0]];
		int xMax = x[pX[n-1]];
		int yMin = y[pY[0]];
		int yMax = y[pY[n-1]];
		int minArea = findArea(xMin, xMax, yMin, yMax);
		if (minArea != 0) {
			
			int remove;
			//remove xMin
			if (y[pX[0]] == yMin)
				remove = findArea (x[pX[1]], xMax, y[pY[1]], yMax);
			else if (y[pX[0]] == yMax) 
				remove = findArea (x[pX[1]], xMax, yMin, y[pY[n-2]]);
			else
				remove = findArea(x[pX[1]], xMax, yMin, yMax);
			if (remove < minArea)
				minArea = remove;
			//remove xMax
			if (y[pX[n-1]] == yMin)
				remove = findArea (xMin, x[pX[n-2]], y[pY[1]], yMax);
			else if (y[pX[n-1]] == yMax) 
				remove = findArea (xMin, x[pX[n-2]], yMin, y[pY[n-2]]);
			else
				remove = findArea(xMin, x[pX[n-2]], yMin, yMax);
			if (remove < minArea)
				minArea = remove;
			//remove yMin
			if (x[pY[0]] == xMin)
				remove = findArea (x[pX[1]], xMax, y[pY[1]], yMax);
			else if (x[pY[0]] == xMax) 
				remove = findArea (xMin, x[pX[n-2]], y[pY[1]], yMax);
			else
				remove = findArea(xMin, xMax, y[pY[1]], yMax);
			if (remove < minArea)
				minArea = remove;
			//remove yMax
			if (x[pY[n-1]] == xMin)
				remove = findArea (x[pX[1]], xMax, yMin, y[pY[n-2]]);
			else if (x[pY[n-1]] == xMax) 
				remove = findArea (xMin, x[pX[n-2]], yMin, y[pY[n-2]]);
			else
				remove = findArea(xMin, xMax, yMin, y[pY[n-2]]);
			if (remove < minArea)
				minArea = remove;
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")));
		System.out.println(minArea);
		out.println(minArea);
	
		out.close();
		scan.close();
	}
	public static int findArea (int xMin, int xMax, int yMin, int yMax) {
		return (xMax-xMin)*(yMax-yMin);
	}
	

}
