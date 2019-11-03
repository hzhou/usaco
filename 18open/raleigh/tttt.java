import java.util.*;
import java.io.*;

public class tttt{
    public static void main(String[] args) throws IOException{
    	Scanner scan = new Scanner(new File("tttt.in"));
	char[][] board = new char[3][3];
	for (int i=0; i<3; i++){
	    String line = scan.next();
	    for(int j=0; j<3; j++){
	    	board[i][j] = line.charAt(j);
	    }
	}
	int oneteam = 0;
	
	//rows
	for(int i=0; i<3; i++){	    
    	    oneteam += one(board[i][0],board[i][1],board[i][2]);
	}

	//columns
	for(int j=0; j<3; j++){
	    oneteam += one(board[0][j],board[1][j],board[2][j]);
	}
	
	//diagonals
	oneteam += one(board[0][0],board[1][1],board[2][2]);	
	oneteam += one(board[0][2],board[1][1],board[2][0]);


	int twoteam = 0;
	
	//rows
	for(int i=0; i<3; i++){	    
    	    twoteam += two(board[i][0],board[i][1],board[i][2]);
	}

	//columns
	for(int j=0; j<3; j++){ 
    	    twoteam += two(board[0][j],board[1][j],board[2][j]);
	}

        //diagonals
	twoteam += two(board[0][0],board[1][1],board[2][2]);
	twoteam += two(board[0][2],board[1][1],board[2][0]);
   
   	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tttt.out")));
	out.println(oneteam);
	out.println(twoteam);
	scan.close();
	out.close();

    }
    public static void one(char a, char b, char c){
    	int onecount = 0;
	if((a == b) && (b == c)){
	    onecount++;
	}
	return onecount;
    }

    public static void two(char a, char b, char c){
    	int twocount = 0;
	if ((a==b) || (b==c) || (c==a)){
	    twocount++;
	}
	return twocount;
    }
}
