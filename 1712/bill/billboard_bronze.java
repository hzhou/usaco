/*
Bill Zheng
~ 1 hour
I needed to make sure I got all of the corner cases which took a long time to solve.
 */

import java.io.*;
import java.util.*;

class billboard {
  public static void main (String [] args) throws IOException {
	//BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\Bronze\\test1.txt"));
    BufferedReader f = new BufferedReader(new FileReader("billboard.in"));
    
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
    
    StringTokenizer st = new StringTokenizer(f.readLine());;
    int[] a = new int[12];
    
    for (int i = 0; i < 12; i++) {
    	if (i== 4 || i == 8) {
    		st = new StringTokenizer(f.readLine());
    	}
    	a[i] = Integer.parseInt(st.nextToken());  
    	System.out.print(a[i] + " ");
    }
    System.out.println();
    
    int totalarea = Math.abs(a[2]-a[0])*Math.abs(a[3]-a[1]) + Math.abs(a[6]-a[4])*Math.abs(a[7]-a[5]);
    System.out.println("TotalArea: " + totalarea);
    
    int minx1 = Math.min(a[10], a[2]);
    int maxx1 = Math.max(a[8], a[0]);
    int miny1 = Math.min(a[11], a[3]);
    int maxy1 = Math.max(a[9], a[1]);
    
    System.out.print(minx1 + " " + maxx1 + " " + miny1 + " " + maxy1 + "\n" );
    if(maxx1 < minx1 && maxy1 < miny1) {
		totalarea -= Math.abs(maxx1-minx1)*Math.abs(maxy1-miny1);
	}
    
    System.out.println("TotalArea: " + totalarea);
    
    int minx2 = Math.min(a[10], a[6]);
    int maxx2 = Math.max(a[8], a[4]);
    int miny2 = Math.min(a[11], a[7]);
    int maxy2 = Math.max(a[9], a[5]);
    if(maxx2 < minx2 && maxy2 < miny2) {
		totalarea -= Math.abs(maxx2-minx2)*Math.abs(maxy2-miny2);
	}

    System.out.println();
    System.out.println(totalarea);
    out.println(totalarea);                      
    out.close();                             
  }
}
