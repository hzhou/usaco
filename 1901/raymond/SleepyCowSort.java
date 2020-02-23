import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class SleepyCowSort {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("sleepy.in"));
        PrintWriter out = new PrintWriter("sleepy.out");

        buf.readLine();
        ArrayList<Integer> splint = IntStream.of(Arrays.stream(buf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray()).boxed().collect(Collectors.toCollection(ArrayList::new));

        for(int i = splint.size() - 2; i >= 0; i--) {
            if(splint.get(i) > splint.get(i + 1)){
                out.println(i + 1);
                break;
            }
            if(i == 0){
                out.println(0);
            }
        }
        out.close();
    }
}