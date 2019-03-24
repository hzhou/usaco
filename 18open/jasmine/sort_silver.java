import java.util.*;
import java.io.*;
public class sort {
	public static ArrayList <HashSet <Integer>> pairs;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("sort.in"));
		int n = scan.nextInt();
		
		IndexNum [] nums = new IndexNum [n];
		for (int i = 0; i < n; i++) 
			nums[i] = new IndexNum (i, scan.nextInt());
		
		Arrays.sort(nums, new Comparator <IndexNum> () {
			public int compare (IndexNum p1, IndexNum p2)
			{
				if (p1.val == p2.val)
					return p1.i - p2.i;
				else
					return p1.val - p2.val;
			}
		});
		
		int largest = 0;
		for (int i = 0; i < n; i++) {
			IndexNum p = nums[i];
			if (p.i > i) {
				int x = p.i-i;
				if (x > largest)
					largest = x;
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sort.out")));
		out.println(largest+1);
		
		out.close();
		scan.close();
	}
}
class IndexNum{
	int i;
	int val;
	IndexNum (int i, int val)
	{
		this.i = i;
		this.val = val;
	}
}