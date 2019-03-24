//Jasmine Zhang
// 1 hour 20 minutes
// All cases passed, needed some cases

import java.util.*;
import java.io.*;
public class hoofball {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("hoofball.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hoofball.out")));
		int n = scan.nextInt();
		int [] cows = new int [n];
		for (int i = 0; i < n; i++)
		{
			cows[i] = scan.nextInt();
		}
		boolean [] right = new boolean [n];
		int [] arrow = new int [n];
		Arrays.sort(cows);
		int [] pass = new int [n];
		pass[0] = cows[1];
		right[0] = true;
		pass[n-1] = cows[n-2];
		arrow[0] = 1;
		arrow[n-1] = -1;
		for (int i = 1; i < n-1; i++)
		{
			int prev = cows[i-1];
			int current = cows[i];
			int next = cows[i+1];
			if ( current - prev <= next - current)
			{
				pass[i] = prev;
				arrow[i] = -1;
				
			}
			else
			{
				pass[i] = next;
				right[i] = true;
				arrow[i] = 1;
			}
		}
		//System.out.println(Arrays.toString(cows));
		//System.out.println(Arrays.toString(pass));
		//System.out.println(Arrays.toString(right));
		
		int ball = 1;
		
		for (int i = 0; i < n-1; i++)
		{
			//int prev = pass[i-1];
			int cow = cows[i];
			int cowPass = pass[i];
			int next = cows[i+1];
			int nextPass = pass[i+1];
			if (nextPass == cow && cowPass == next)
			{
				arrow[i] = 0;
				arrow[i+1] = 0;
				i++;
				ball++;
				//System.out.println(cow + " " + next);
			}
		}
		ball = 0;
		//System.out.println(Arrays.toString(arrow));
		boolean findDiff = true;
		boolean diff = false;
		boolean current = right[0];
		int zeros = 0;
		int start = arrow[0];
		int other = 2;
		if (start == 0)
			zeros++;
		for (int i = 1; i < n-1; i++)
		{
			if (start != 1 && arrow[i] == 1)
			{
				start = arrow[i];
				zeros = 0;
				other = 2;
				ball++;
				//System.out.println(start);
			}
			if (start == -1)
			{
				other = 3;
			}
			if(arrow[i] == 0)
			{
				zeros++;
			}
			if (arrow[i] != start && other == 2)
			{
				other = arrow[i];
			}
			else if (arrow[i]!= start && arrow[i] != other)
			{
				start = arrow[i+1];
				zeros = 0;
				other = 2;
				ball++;
				//System.out.println(start);
				//continue;
			}
			//System.out.println(start + " " + other + " " + zeros + " " + ball );
			int x = i+1;
			if (zeros == 2 && (start != 0|| arrow[i+1] == 0))
			{
				start = arrow[i+1];
				zeros = 0;
				other = 2;
				ball++;
				//System.out.println(start + "asdf");
			}
			
			
		}
		out.println(ball+1);
		scan.close();
		out.close();
	}

}
