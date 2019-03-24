//Jasmine Zhang
//All cases passed, need test case 3
//1 hour
import java.util.*;
import java.io.*;
public class milkorder {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("milkorder.in"));
		int n = scan.nextInt();
		int m = scan.nextInt();
		int k = scan.nextInt();
		
		int [] order = new int [n];
		int [] hier = new int [m];
		
		for (int i = 0; i < m; i++)
			hier[i] = scan.nextInt();

		for (int i = 0; i < k; i++) {
			int val = scan.nextInt();
			int index = scan.nextInt();
			order[index-1] = val;	
		}
		
		for (int i = 0; i < n; i++) {
			if (order[i]!= 0) {
				int hierPos = indexOf(order[i], hier);
				if (hierPos != -1) {
					for (int j = hierPos - 1; j >= 0; j--) {
						int temp = hier[j];
						if (indexOf(temp, order)== -1) {
							int x = i-1;
							while (order[x] != 0)
								x--;
							order[x] = temp;
						}
					}	
				}
			}
		}
		
		int num = indexOf (1,hier);
		if (num != -1) {
			for (int i = 0; i <= num; i++) {
				int temp = hier[i];
				if (indexOf(temp, order) == -1) {
					int x;
					if (i == 0)
						x = 0;
					else 
						x = indexOf(hier[i-1], order);
					while (order[x] != 0)
						x++;
					order[x] = temp;
				}
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milkorder.out")));
		int x = indexOf(1, order);
		if (x == -1)
			out.println(indexOf(0,order)+1);
		else
			out.println(x+1);
		
		scan.close();
		out.close();
	}
	public static int indexOf (int x, int [] array)
	{
		for (int i = 0; i < array.length; i++)
		{
			if (array[i] == x)
				return i;
		}
		return -1;
	}
}
