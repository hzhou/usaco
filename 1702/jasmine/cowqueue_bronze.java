//Jasmine Zhang
//February OldCode.Bronze 2017 - cowqueue
//10 minutes, all cases passed
import java.util.*;
import java.io.*;

public class cowqueue {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("cowqueue.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
		int n = scan.nextInt();
		Time [] times = new Time [n];
		for (int i = 0; i < n; i++)
		{
			times[i] = new Time (scan.nextInt(), scan.nextInt());
		}
		Arrays.sort(times);
		
		int totalTime = times[0].arrive + times[0].time;
		for (int i = 1; i < n; i++)
		{
			int a = times[i].arrive;
			int t = times[i].time;
			if (a > totalTime)
			{
				totalTime = a +t;
			}
			else
			{
				totalTime += t;
			}
		}
		out.println(totalTime);
		scan.close();
		out.close();
	}

}
class Time implements Comparable
{
	int arrive;
	int time;
	Time (int arrive, int time)
	{
		this.arrive = arrive;
		this.time = time;
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		Time t = (Time)o;
		if (this.arrive == t.arrive)
			return this.time - t.time;
		else
			return this.arrive - t.arrive;
	}
	
}
