//Jasmine Zhang
//15 minutes, all cases passed
import java.util.*;
import java.io.*;
public class taming {
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("taming.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("taming.out")));
		int n = scan.nextInt();
		int log = scan.nextInt();
		int lastLog = 1;
		int breakouts = 1;
		int uncertainties = 0;
		int lastBreak = 1;
		boolean good = true;
		for (int i = 2; i <= n; i++)
		{
			log = scan.nextInt();
			if (log == -1)
			{
				uncertainties++;
				continue;
			}
			if (i - log < lastBreak)
			{
				out.println(-1);
				good = false;
				break;
			}
			if (i -log == lastBreak)
			{
				//System.out.println(i + " " + lastLog);
				//System.out.println((i-1-lastLog));
				uncertainties -= (i-1-lastLog);
			}
			else 
			{
				lastBreak = i-log;
				//System.out.println(i);
				breakouts++;
				if (log != 0)
					uncertainties-= log;
			}
			lastLog = i;
			
		}
		if (good)
			out.println(breakouts + " " + (breakouts + uncertainties));
		
		scan.close();
		out.close();
	}
}
