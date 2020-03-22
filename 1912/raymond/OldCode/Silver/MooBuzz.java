package OldCode.Silver;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

//Old code
public class MooBuzz {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("moobuzz.in"));
        //BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(buf.readLine());
        FileWriter yoink = new FileWriter("moobuzz.out");

        int n = Integer.parseInt(st.nextToken());

        int counts = n / 3 + n / 5 - n / 15;
        int lastCounts;

        while(counts > 5) {
            lastCounts = (n / 3 + n / 5 - n / 15);
            n += counts;
            counts = (n / 3 + n / 5 - n / 15) - lastCounts;
        }


        while(counts > 0){
            ++n;
            if(!(n % 3 == 0 || n % 5 == 0)){
                counts--;
            }
        }

        yoink.append(String.valueOf(n));
        yoink.close();
    }
}
