//Jasmine Zhang
//Finished in 5 minutes, all cases passed 
import java.util.*;
import java.io.*;
public class teleport {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner scan = new Scanner (new File ("teleport.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
		int a = scan.nextInt();
		int b = scan.nextInt();
		int x = scan.nextInt();
		int y = scan.nextInt();
		int noTele = Math.abs(a-b);
		int tele1 = Math.abs(a-x) + Math.abs(b-y);
		int tele2 = Math.abs(a-y) + Math.abs(b-x);
		int teleMin = Math.min(tele1, tele2);
		out.println(Math.min(teleMin, noTele));
		
		out.close();
		scan.close();

	}

}
