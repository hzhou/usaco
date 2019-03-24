//8/10 cases passed
import java.util.*;
import java.io.*;
public class snowboots {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("snowboots.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("snowboots.out")));
		int n = scan.nextInt();
		int b = scan.nextInt();
		int [] depth = new int [n];
		for (int i= 0; i < n; i++)
			depth[i] = scan.nextInt();
		Boot [] boots2 = new Boot [b];
		Stack <Boot> boots = new Stack <Boot> ();
		for (int i = 0; i < b; i++)
		{
			boots2[i] = (new Boot(scan.nextInt(),scan.nextInt()));
		}
		boolean [] canStep = new boolean [n];
		int pair = 0;
		int maxStep = 0;
		int maxDepth = 0;
		for (int i = 0; i < b; i++)
		{
			int dist = 1;
			Boot boot = boots2[i];
			//System.out.println("as");
			
			for (int j = 0; j < n; j++)
			{
				//System.out.println(n);
				//System.out.println(Arrays.toString(canStep));
				
				if (canStep[j]&&depth[j] <= boot.depth)
					dist = 1;
				if (dist > boot.distance)
				{
					continue;
				}
				if (depth[j] > boot.depth)
				{
					dist++;
					continue;
				}
				canStep[j] = true;
				dist = 1;
				//System.out.println(i + " " + j);
				//System.out.println(boot.depth + " " + boot.distance);
				//System.out.println(j== n-1);
				
				
			}
			//System.out.println(Arrays.toString(canStep));
			if (canStep[n-1])
				break;
			pair++;
		}
		out.println(pair);
		/*
		int pos = 0;
		Boot current = boots.pop();
		int discard = 0;
		while (pos < n)
		{
			int newPos = -1;
			for (int i = current.distance ;i > 0; i++)
			{
				if (depth[i+pos] <= current.depth)
				{
					newPos = i+pos;
					break;
				}
			}
			if (newPos == -1)
			{
				
				discard++;
				
			}
		}
			*/
		scan.close();
		out.close();

	}

}
class Boot 
{
	int depth;
	int distance;
	Boot (int de, int di)
	{
		depth = de;
		distance = di;
	}
}
