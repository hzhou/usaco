import java.io.*;
import java.util.*;

public class cowtip {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("cowtip.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowtip.out")));
	    int n = Integer.parseInt(f.readLine());
	    int [][] tip = new int [n][n];
	    for (int i = 0; i < n; i++)
	    {
	    	String s = f.readLine();
	    	for (int j = 0; j < n; j++)
	    	{
	    		tip[i][j] = Integer.parseInt(s.substring(j, j+1));
	    	}
	    }
	    int flips = 0;
	    
    	
	   while (all0(tip, n, n) == false)
	   {
	    	int [] a = largest(tip);
	    	tip = toggle(tip, a[0], a[1]);
	    	flips++;
	    	
	    	
	   }
	   out.println(flips);
	    //System.out.println("asdf");
	    out.close();    
	    f.close(); 

	}
	public static boolean all0 (int [][] array,  int length, int width)
	{
		boolean zero = true;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (array[i][j] != 0)
				{
					zero = false;
				}
			}
		}
		return zero;
	}
	
	public static int [][] toggle (int [][] array, int x, int y)
	{
		for (int i = 0; i <= y; i++)
		{
			for (int j = 0; j <= x; j++)
			{
				if (array[i][j] == 0)
				{
					array[i][j] = 1;
				}
				else
				{
					array[i][j] = 0;
				}
			}
		}
		return array;
	}
	public static int [] largest (int [][] array)
	{
		int x = 0;
		int y = 0;
		for (int i = 0; i < array.length; i++)
		{
			for (int j = 0; j < array.length; j++)
			{
				if (array[i][j] == 1)
				{
					x = i;
					y = j;
				}
			}
		}
		int [] a = {y,x};
		//System.out.println(y + " " +  x);
		return a; 
	}

}
