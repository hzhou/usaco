//not complete
import java.util.*;
import java.io.*;
public class teleport {
	static ArrayList <Manure> manures;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("teleport.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
		long n = scan.nextInt();
		long total = 0;
		
		
		long portal = 0;
		manures = new ArrayList <Manure> ();
		ArrayList <Long> far = new ArrayList <Long> ();
		long test = 0;
		long pos = 0;
		long neg = 0;
		long posC = 0;
		long negC = 0;
		for (int i= 0; i < n; i++)
		{
			Manure m = new Manure (scan.nextInt(), scan.nextInt());
			if (m.distance <= Math.abs(m.closer))
			{
				total += m.distance;
			}
			else
			{
				manures.add(m);
				far.add(m.farther);
				test += m.farther;
				if (m.farther > 0)
				{
					pos += m.farther;
					posC++;
				}
				else
				{
					neg += m.farther;
					negC++;
				}
			}
			/*
			else if (portal == 0)
			{
				portal = m.farther;
				total += Math.abs(m.closer);
			}
			else
			{
				long sum = (Math.abs(m.closer) + Math.abs(portal-m.farther));
				if (sum > m.distance)
					total += m.distance;
				else 
					total += sum;
			}
			*/
			
		}
		Collections.sort(far);
		int x = far.size();
		//System.out.println(far.get(x/2));
		long posSum;
		if (posC == 0)
			posSum = -1;
		else
			posSum = usePortal(pos/posC);
		long negSum;
		if (negC == 0)
			negSum = -1;
		else
			negSum = usePortal(neg/negC);
		long bestSum = 0; 
		long b = 0;
		if (posSum > negSum && negSum != -1)
		{
			b = neg/negC;
			bestSum = negSum;
		}
		else
		{
			b = pos/posC;
			bestSum = posSum;
		}
		//System.out.println(b + " " + bestSum);
		long bPortal = 0;
		if (manures.size() > 2)
		{
			
			bPortal = bestPortal (b, (int) Math.log10(Math.abs(b)));
			
		}
		else
		{
			bPortal = usePortal(far.get(0));
		}
		test /= x;
		//usePortal(test);
	//System.out.println(usePortal())
		//System.out.println(total+usePortal(pos/posC));
		//System.out.println(total+usePortal(neg/negC));
		//System.out.println(total+bestSum);
		//System.out.println(bPortal);
		//System.out.println(b + " " + usePortal(b));
		//System.out.println(b+10000000 + " " + usePortal(b+10000000));
		//System.out.println(b-10000000 + " " + usePortal(b-10000000));
		//System.out.println(bPortal + " " + usePortal(bPortal));
		out.println(usePortal(bPortal)+total);
		//System.out.println(usePortal(bPortal-20000000)+total + " asdf");
		//System.out.println(bPortal-20000000);
		//System.out.println(usePortal(bPortal+10)+total + " asdf");
		
		scan.close();
		out.close();
		//System.out.println(small);
		//System.out.println(bestI)
		//-70347469
		//1156616086571
		
		/*
		
		long best = far.get(x/2);
		long prev = far.get((x/2) -1);
		long next = far.get((x/2) +1);
		int bestI = x/2;
		long bSum = 0;
		long pSum = 0;
		long nSum = 0;
		
		
		
		for (int i = 0; i < x; i++)
		{
			long num = far.get(i);
			bSum += Math.abs(num-best);
			pSum += Math.abs(num-prev);
			nSum += Math.abs(num-next);
		}
		
		System.out.println(bSum);
		System.out.println(pSum);
		System.out.println(nSum);
		
		
		if (bSum >= pSum || bSum >= nSum)
		{
			int add;
			if (pSum < nSum)
			{
				add = -1;
				bestI--;
				best = prev;
				bSum = pSum;
			}
			else
			{
				add = 1;
				bestI++;
				best = next;
				bSum = nSum;
			}
			long newSum = 0;
			int newI = bestI + add;
			long newNum = far.get(newI);
			for (int i = 0; i < x; i++)
			{
				long num = far.get(i);
				newSum += Math.abs(num-newNum);
			}
			while (newSum < bSum)
			{
				bSum = newSum;
				bestI = newI;
				best = newNum;
				newSum = 0;
				newI = bestI + add;
				newNum = far.get(newI);
				for (int i = 0; i < x; i++)
				{
					long num = far.get(i);
					newSum += Math.abs(num-newNum);
				}
			}
			portal = best;
		}
		//else*/
		
		//System.out.println(usePortal(-56487792));
		
		//System.out.println(usePortal(-46487792));
		//System.out.println(usePortal(-66487792));
		/*
		long small = 0;
		for (int j = 0; j < x; j++)	
		{
			portal = far.get(j);
			long s = 0;
			for (int i = 0; i < x; i++)
			{
				
				Manure m = manures.get(i);
				long sum = (Math.abs(m.closer) + Math.abs(portal-m.farther));
				if (sum > m.distance)
					s += m.distance;
				else	 
					s += sum;
			}
			if (j == 0)
			{
				small = s; 
			}
			else if (s < small)
			{
				small = s;
				//System.out.println(portal + " " + small);
			}
		}
		*/
		
		
		
		

	}
	public static long usePortal (long long1)
	{
		long s = 0;
		//System.out.println(long1 + "asdf");
		for (int i = 0; i < manures.size(); i++)
		{
			
			Manure m = manures.get(i);
			long sum = (Math.abs(m.closer) + Math.abs(long1-m.farther));
			//System.out.println(long1 + " " + m.farther);
			//System.out.println(m.closer);
			//System.out.println(Math.abs(long1-m.farther));
			if (sum > m.distance)
				s += m.distance;
			else	
			{
				s += sum;
				//System.out.println("hit");
			}
			//System.out.println(s);
			
		}
		//System.out.println(s + " " + long1);
		return s;
	}
	public static long bestPortal (long portal, int power)
	{
		if (power == -1)
			return portal;
		long bestSum = usePortal(portal);
	
		//System.out.println(power+portal);
		//System.out.println(portal-power);
		long ten = (long) Math.pow(10, power);
		long prev = usePortal(portal - ten);
		long next = usePortal(portal + ten);
		long add = 0;
		
		//System.out.println(ten);
		//System.out.println(bestSum);
		//System.out.println(prev);
		//System.out.println(next);
		if (bestSum < prev && bestSum < next)
		{
			return bestPortal (portal, power-1);
		}
		if (bestSum > prev)
		{
			add = -1* ten;
			//bestI--;
			portal = portal-ten;
		}
		else if (bestSum > next)
		{
			add = ten;
			//bestI++;
			//small = next;
			portal = portal+ten;
		}
		
		//System.out.println(add);
		long sum = usePortal(portal+add);
		long n = portal + add;
		
		//System.out.println(portal + " " +  n);
		//System.out.println(usePortal(portal));
		//System.out.println(usePortal(n));
		//System.out.println(sum + " " + bestSum);
		
		//System.out.println(portal + " " + (portal +add));
		while (sum < bestSum)
		{
			bestSum = sum;
			portal += add;
			sum = usePortal(portal+add);
			n = portal + add;
			/*
			System.out.println(portal + " " +  n);
			System.out.println(usePortal(portal));
			System.out.println(usePortal(n));
			System.out.println(sum + " " + bestSum);
			System.out.println(portal + " " + bestSum);
			*/
		}
		return bestPortal(portal, power-1);
	}

}
class Manure 
{
	long closer;
	long farther;
	long distance;
	Manure (long x, long y)
	{
		if (Math.abs(x) < Math.abs(y))
		{
			closer = x;
			farther = y;
		}
		else
		{
			closer = x;
			farther = y;
		}
		distance = Math.abs(x-y);
	}
}

