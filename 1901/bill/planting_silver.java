/*
ID: ml2963
Tests: **********
Very easy once you find how the solution works.
 */

import java.io.*;
import java.util.*;

class planting {
  public static void main (String [] args) throws IOException {
	//BufferedReader f = new BufferedReader(new FileReader("D:\\eclipse-workspace\\USACO\\OldCode.Silver\\testSilver.txt"));
    BufferedReader f = new BufferedReader(new FileReader("planting.in"));
    
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("planting.out")));
    
    StringTokenizer st = new StringTokenizer(f.readLine());
	
    int n = Integer.parseInt(st.nextToken());  
    int[] data = new int[(n-1)*2];
    int k = 0;
    for (int i = 0; i < n-1; i++) {
    	st = new StringTokenizer(f.readLine());
    	for (int j = 0; j < 2; j++) {
    		data[k] = Integer.parseInt(st.nextToken());  
    		k++;
    	}
    }
    int[] a = new int[n+1];
    for (int i = 0; i < (n-1)*2; i++) {
    	a[data[i]]++;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > max) {
    		max = a[i];
    	}
    }
    System.out.println(max+1);
    
    out.println(max +1);                      
    out.close();                             
  }
}
