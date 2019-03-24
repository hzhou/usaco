import java.util.*;
import java.io.*;
public class poetry {
	//might have to mod along the way
	static long mod = 1000000007;
	static int n,m,k;
	static HashMap <Integer,Integer> sOccur = new HashMap <Integer,Integer> ();
	static HashMap <Long,Long> syllEnd = new HashMap <Long,Long> ();
	static HashMap <Integer,Integer> rPoss = new HashMap <Integer,Integer> ();
	static long [] syllComb;
	static long [] sUsed;
	static long [] sComb;	
	static int [] rhym = new int [26];
	static int [] rClass = new int [5000];
	public static void main(String[] args) throws IOException{
		
		Scanner scan = new Scanner (new File ("poetry.in"));
		n = scan.nextInt();
		m = scan.nextInt();
		k = scan.nextInt();
		
		int [] syllables = new int [n];
		int [] rhyme = new int [n];
		for (int i = 0; i < n; i++) {
			int s = scan.nextInt();
			int r = scan.nextInt();
			syllables[i] = s;
			rhyme[i] = r;
			
			Integer tot = sOccur.get(s);
			if (tot == null)
				sOccur.put(s, 1);
			else
				sOccur.put(s, tot+1);
		}
		
		int size = sOccur.size();
		long [] s = new long [size];
		sUsed = new long [size];
		long [] occur = new long [size];
		
		Iterator <Integer> it = sOccur.keySet().iterator();
		int in = 0;
		while (it.hasNext()) {
			int key = it.next();
			s[in] = key;
			occur [in] = sOccur.get(key);
			in++;
		}
		
		for (int i = 0; i < m; i++) {
			char c = scan.next().charAt(0);
			int num = c-65;
			rhym[num] += 1;
			//System.out.println(num);
			//rhym[i] = 
		}
		
		syllComb((int)(k), size, s, occur);
		for (int i = 0; i < size; i++) {
			long sC = sComb[(int) (k-s[i])];
			syllEnd.put(s[i], sC);
			
		}
		//System.out.println(syllEnd);
		
		for (int i = 0; i < n; i++) {
			long syll = syllables[i];
			int r = rhyme[i]-1;
			//System.out.println(syll);
			//System.out.println(syllEnd.get(syll));
			rClass[r] += syllEnd.get(syll);
		}
		//System.out.println(Arrays.toString(rClass));
		
		long [] lines = new long [26];
		int total = 1;
		for (int i = 0; i < 26; i++) {
			if (rhym[i] == 0)
				continue;
			for (int j = 0; j < 5000; j++) {
				if (rClass[j] == 0)
					continue;
				lines[i] += Math.pow(rClass[j],rhym[i]);
				//System.out.prin
				///lines[i] += Math.pow(rhym[j],rClass[j]);
			}
			lines[i]%= mod;
			total *= lines[i];
			
		}
		
		//System.out.println(Arrays.toString(lines));
		System.out.println(total%mod);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("poetry.out")));
		out.println(total%mod);
	
		out.close();
		scan.close();
	}
	public static long syllComb (int k, int size, long [] s, long [] occur) {
		sComb = new long [k+1];
		HashMap <Integer, Integer> syllC = new HashMap <Integer,Integer> ();
		sComb[0] = 1;
		
		
		
		long [] temp = new long [k+1];
		for (int i = 0; i < size; i++) {
			for (long j = s[i]; j <= k; j++) {
				
				sComb[(int) j] += occur[i]*sComb[(int)(j-s[i])];
				//temp[(int)j] = sComb[(int)j];
			}
			/*
			for (long j = k; j >= s[i]; j--) {
				if (j % s[i] == 0)
					continue;
				sComb[(int) j] += occur[i]*sComb[(int)(j-s[i])];
				//temp[(int)j] = sComb[(int)j];
			}
			*/
		}
		
		
		/*
		for (int i = 0; i < size; i++) {
			for (long j = s[i]; j <= k; j++) {
				temp[(int) j] -= occur[i]*sComb[(int)(j-s[i])];
				
			}
			//System.out.println(Arrays.toString(temp));
			syllEnd.put(s[i],temp[k]*-1);
			temp = new long [k+1];
		}
		*/
		
		System.out.println(Arrays.toString(sComb));
		//System.out.println(syllEnd);
		return sComb[k];
	}

}
