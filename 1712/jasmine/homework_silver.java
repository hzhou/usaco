//Jasmine Zhang
//December 2017 OldCode.Silver - Homework
//1 hour 30 minutes to clear all cases
//Needed the second test case to pass 9 and the last case to pass all 10 cases 


import java.io.*;
import java.util.*;
public class homework {

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner scan= new Scanner(new File("homework.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("homework.out")));
		int n = scan.nextInt();
		//for (int i = 0)
		int [] scores = new int[n];
		for (int i = 0; i < n; i++)
		{
			scores[i] = scan.nextInt();
		}
		int smallest = 0;
		int total = 0;
		int num = 1;
		if (scores[n-1] < scores[n-2])
		{
			smallest = scores[n-1];
			total = scores[n-2];
		}
		else
		{
			smallest = scores[n-2];
			total = scores[n-1];
		}
		AvgPair [] aPairs = new AvgPair [n-2];
		aPairs[n-3] = new AvgPair (total, num,n-2);
		//System.out.println(aPairs[n-3]);
		for (int i = n-4; i >= 0; i--)
		{
			int x = scores[i+1];
			if (x < smallest)
			{
				total += smallest;
				smallest = x;
			}
			else
			{
				total += x;
			}
			num++;
			aPairs[i]= new AvgPair (total,num,i+1);
			//System.out.println(aPairs[i] + " " + i + " " + aPairs[i].total/aPairs[i].num);
		}
		
		Arrays.sort(aPairs);
		//System.out.println(aPairs[0]);
		out.println(aPairs[0].i);
		int i = 1;
		while (i <= n-3 && (Math.abs((aPairs[i].total/aPairs[i].num) - (aPairs[0].total/aPairs[0].num)) <.00001))
		{
			out.println(aPairs[i].i);
			i++;
		}
		
		scan.close();
		out.close();
	}

}
class AvgPair implements Comparable
{
	int total;
	double num;
	int i;
	AvgPair (int total, double num ,int i)
	{
		this.total = total;
		this.num = num;
		this.i = i;
	}
	
	@Override
	public int compareTo(Object o) {
		AvgPair p = (AvgPair) o;
		//System.out.println(this.total/num + " " + p.total/p.num);
		if (Math.abs(this.total/num - p.total/p.num) <.00001)
			return (int) (this.i - p.i);
		else
			if  (this.total/num < p.total/p.num) 
				return 1;
			else 
				return -1;
	}
	
	//@Override
	public String toString ()
	{
		return total + " " + num + " " + i;
	}
}
