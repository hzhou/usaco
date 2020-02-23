import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class GuessTheAnimal {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("guess.in"));
        PrintWriter out = new PrintWriter("guess.out");
        StringTokenizer st;

        ArrayList<ArrayList<String>> characteristics = new ArrayList<>();
        int lines = Integer.parseInt(buf.readLine());

        for(int i = 0; i < lines; i++){
            ArrayList<String> cur = new ArrayList<>();
            st = new StringTokenizer(buf.readLine());
            st.nextToken();

            int temp = Integer.parseInt(st.nextToken());

            for(int j = 0; j < temp; j++){
                cur.add(st.nextToken());
            }

            characteristics.add(cur);
        }
        buf.close();

        int max = 0;
        for(int i = 0; i < characteristics.size(); i++){
            for(int j = i + 1; j < characteristics.size(); j++){
                max = Math.max(inCommon(characteristics.get(i), characteristics.get(j)), max);
            }
        }
        out.println(max + 1);
        out.close();
    }

    public static int inCommon(ArrayList<String> a, ArrayList<String> b){
        int counter = 0;
        for(String cur : a){
            for(String cur2 : b){
                if(cur.equals(cur2)) {
                    counter++;
                }
            }
        }
        return counter;
    }
}
