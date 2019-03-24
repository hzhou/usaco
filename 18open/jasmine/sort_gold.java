//Jasmine Zhang
//passed 4 cases, time out on the rest
//30 minutes
import java.util.*;
import java.io.*;
import javafx.util.Pair;;
public class sort {
	public static ArrayList <HashSet <Integer>> pairs;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("sort.in"));
		int n = scan.nextInt();
		
		iNum [] nums = new iNum [n];
		for (int i = 0; i < n; i++) 
			nums[i] = new iNum (i, scan.nextInt());
		
		Arrays.sort(nums, new Comparator <iNum> () {
			public int compare (iNum p1, iNum p2)
			{
				if (p1.val == p2.val)
					return p1.i - p2.i;
				else
					return p1.val - p2.val;
			}
		});
		System.out.println(Arrays.toString(nums));
		
		
		//Every iteration of the loop, Bessie swaps the two most out of place numbers 
		//if you separate the array at a specific point, the maximum of numbers on the wrong side 
		//of the separation point is the answer
		int max = 0;
		for (int i = 0; i < n-1; i++) {
			int s = 0;
			for (int j = 0; j <= i; j++) {
				if (nums[j].i > i)
					s++;
			}
			if (s > max)
				max = s;
			/*
			else if (s < max)
				break;
			*/
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sort.out")));
		System.out.println(max);
		out.println(max);
		
		out.close();
		scan.close();
	}
}


class iNum{
	int i;
	int val;
	iNum (int i, int val)
	{
		this.i = i;
		this.val = val;
	}
	public String toString () {
		return i + " " + val;
	}
}
