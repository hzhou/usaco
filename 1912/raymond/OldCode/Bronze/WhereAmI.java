package OldCode.Bronze;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

//Old code
public class WhereAmI {
    public static void main(String[] args) throws IOException {
        BufferedReader buf = new BufferedReader(new FileReader("whereami.in"));
        //BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
        FileWriter yoink = new FileWriter("whereami.out");

        buf.readLine();
        String bruh = buf.readLine();

        for(int i = 1; i <= bruh.length(); i++){
            boolean lowest = true;
            for(int j = 0; j <= bruh.length() - i; j++){
                String cur = bruh.substring(j, j + i);

                String temp = bruh;

                int index = temp.indexOf(cur);
                int count = 0;
                while (index != -1) {
                    count++;
                    temp = temp.substring(index + 1);
                    index = temp.indexOf(cur);
                }

                if(count >= 2){
                    lowest = false;
                    break;
                }
            }
            if(lowest){
                yoink.append(String.valueOf(i));
                yoink.close();
                break;
            }
        }
    }
}
