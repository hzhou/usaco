//Jasmine Zhang
//All cases passed
//30 minutes 
import java.io.*;
import java.util.*;
public class lemonade {
	public static void main (String [] args) throws IOException {
		Scanner scan = new Scanner (new File ("lemonade.in"));
		int n = scan.nextInt();
		int min = 0;
		ArrayList <Integer> nums = new ArrayList <Integer> ();
		
		for (int i = 0; i < n; i++)
		{
			int temp = scan.nextInt();
			if (temp >= n) {
				min++;
			}
			else {
				nums.add(temp);
			}
		}
		Collections.sort(nums);
		
		if (nums.size() > 1)
		{
			int x = nums.size() -1;
			int num = nums.get(x);
			while (x >= 0 && num >= min)
			{
				min++;
				x--;
				num = nums.get(x);
			}
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lemonade.out")));
		out.println(min);
		
		scan.close();
		out.close();
		

	}

}
