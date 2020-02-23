import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Shell {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("shell.in"));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        PrintWriter out = new PrintWriter("shell.out");

        int n = Integer.parseInt(st.nextToken());

        ArrayList<Integer> guesses = new ArrayList<>();
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(buf.readLine());
            a.add(Integer.parseInt(st.nextToken()));
            b.add(Integer.parseInt(st.nextToken()));
            guesses.add(Integer.parseInt(st.nextToken()));
        }

        int maxGuesses = Math.max(correctGuesses(a, b, guesses, 1), correctGuesses(a, b, guesses, 2));
        out.println(Math.max(maxGuesses, correctGuesses(a, b, guesses, 3)));
        out.close();
    }

    private static int correctGuesses(ArrayList<Integer> a, ArrayList<Integer> b, ArrayList<Integer> guesses, int startingPos){
        int counter = 0;
        for(int i = 0; i < guesses.size(); i++){
            if(startingPos == a.get(i)){ startingPos = b.get(i); }
            else if(startingPos == b.get(i)){ startingPos = a.get(i);}

            if(guesses.get(i) == startingPos){ counter++; }
        }
        return counter;
    }
}