//Jasmine Zhang
//All cases passed, 20 minutes
import java.util.*;
import java.io.*;
public class blocks {
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("blocks.in"));
		int n = scan.nextInt();
		
		String [] list1 = new String [n];
		String [] list2 = new String [n];
		for (int i = 0; i< n; i++) {
			list1[i] = scan.next();
			list2[i] = scan.next();
		}
		
		int [] total = new int [26];
		for (int i = 0; i < n; i++) {
			word(list1[i], list2[i], total);
		}
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
		for (int i = 0; i < 26; i++)
			out.println(total[i]);
		
		out.close();
		scan.close();
	}
	public static void word (String word1, String word2, int [] total)
	{
		int [] temp1 = new int [26];
		for (int i = 0; i < word1.length(); i++) {
			char c = word1.charAt(i);
			temp1[c-'a'] += 1;
		}
		
		int [] temp2 = new int [26];
		for (int i = 0; i < word2.length(); i++) {
			char c = word2.charAt(i);
			temp2[c-'a'] += 1;
		}
		
		for (int i = 0; i < 26; i++) {
			total[i] += Math.max(temp1[i], temp2[i]);
		}
	}
}
