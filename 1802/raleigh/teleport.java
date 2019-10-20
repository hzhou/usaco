import java.util.*;
import java.lang.Math;
import java.io.*;

public class teleport{
    public static void main(String[] args) throws IOException{
	Scanner scan = new Scanner(new File("teleport.in"));
	int start=0,end=0,teleend=0,telestart=0;
	for(int i=0; i<4; i++){
	    start = scan.nextInt();
	    end = scan.nextInt();
	    teleend  = scan.nextInt();
	    telestart = scan.nextInt();
	}	

	int toteleport = Math.abs(start - telestart);
	int tofinal = Math.abs(teleend - end);
	int teledist = toteleport + tofinal;

	int notele = Math.abs(start - end);
	
	int min;
	if(notele > teledist){
	    min = teledist;
	}
	else{
	    min = notele;
	}
	
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
	out.println(min);
	out.close();
	scan.close();
    }
}
