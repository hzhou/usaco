//Jasmine Zhang
//All cases passed
//30 minutes
import java.util.*;
import java.io.*;
public class family {
	static HashMap <String, String> relation;
	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner (new File ("family.in"));
		int n = scan.nextInt();
		String a = scan.next();
		String b = scan.next();
		
		relation = new HashMap <String, String> ();
		for (int i = 0; i < n; i++) {
			String mom = scan.next();
			String daughter = scan.next();
			relation.put(daughter, mom);
		}
		
		ArrayList <String> aFam = famTree(a);
		aFam.add(0, a);
		ArrayList <String> bFam = famTree(b);
		bFam.add(0, b);
		
		ArrayList <String> older;
		ArrayList <String> younger;
		if (aFam.size() < bFam.size()) {
			older = aFam;
			younger = bFam;
		}
		else {
			older = bFam;
			younger = aFam;
		}
		
		int common = commonAncestor(older, younger);
		String old = older.get(0);
		String young = younger.get(0);
		
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("family.out")));
		if (common == -1)
			out.println("NOT RELATED");
		else if (younger.get(common).equals(old)) {
			String before = "";
			while (common >= 3) {
				before += "great-";
				common--;
			}
			if (common == 2)
				before += "grand-";
			out.println(old + " is the " + before + "mother of " + young);
		}
		else if (common == 1)
			out.println("SIBLINGS");
		else if (older.get(1).equals(younger.get(common))) {
			String before = "";
			common--;
			while (common >= 2) {
				before += "great-";
				common--;
			}
			out.println(old + " is the " + before + "aunt of " + young);
		}
		else
			out.println("COUSINS");
		
		out.close();
		scan.close();
	}
	public static ArrayList <String> famTree (String s)
	{
		ArrayList <String> fam = new ArrayList <String> ();
		while(relation.containsKey(s)) {
			fam.add(relation.get(s));
			s = relation.get(s);
		}
		return fam;
	}
	
	//-1 = no common ancestor
	public static int commonAncestor (ArrayList <String> older, ArrayList <String> younger)
	{
		int count = 0;
		for (String s : younger) {
			if (older.contains(s))
				return count;
			count++;
		}
		return -1;
	}

}
