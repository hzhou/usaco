import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Brian Lu
 * 
 * 66m 24s 459ms INCOMPLETE (||XXXXXXXX)
 * 
 * I think this problem was a litte harder than the others, but I still did it 
 * rather weirdly. I did spend a decent period of time planning the program, but
 * really only outlined the logic flow, and not the actual program structure 
 * itself, so what came from that was some ungodly amount of nesting that's 
 * virtually impossible to debug.
 * 
 * So yeah, I'll come back to this later, but this is already late and stuff, 
 * so that's that.
 * 
 */
public class badmilk {

    /**
     * @param args the command line arguments
     */
    
    static List<Integer> milkExclusions = new ArrayList<Integer>();
    static List<Integer[]> milkLinks = new ArrayList<>();
    
    static int[][] events;
    static int[][] sickPeople;
    
    static int maxDose = 0;
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("badmilk.in"));
        String[] temp = sc.nextLine().split(" ");
        events = new int[Integer.parseInt(temp[2])][3];
        sickPeople = new int[Integer.parseInt(temp[3])][2];
        for (int i = 0; i < events.length; i++) {
            int[] event = scan(sc);
            events[i] = event;
            milkLinks.add(new Integer[]{event[1], event[0]});
        }
        for (int i = 0; i < sickPeople.length; i++) {
            sickPeople[i] = scan(sc);
        }
        for (int[] sickPerson : sickPeople) {
            for (int[] event : events) {
                if (event[0] == sickPerson[0] && event[2] < sickPerson[1]) {
                    for (Integer[] link : milkLinks) {
                        if (link[0].intValue() == event[1]) {
                            for (int[] reverseTimeSickPerson : sickPeople) {
                                if (reverseTimeSickPerson[0] == link[0].intValue()) {
                                    boolean reversePersonDrank = false;
                                    for (int[] reverseTimeEvent : events) {
                                        if (link[1].intValue() == event[1] && 
                                                reverseTimeEvent[0] == reverseTimeSickPerson[0] && 
                                                reverseTimeEvent[2] < reverseTimeSickPerson[1]) {
                                            reversePersonDrank = true;
                                        }
                                    }
                                    if (reversePersonDrank) {
                                        int count = 0;
                                        for (Integer[] reverseLink : milkLinks) {
                                            if (reverseLink[0].intValue() == link[0].intValue()) {
                                                count++;
                                            }
                                        }
                                        if (count > maxDose) {
                                            maxDose = count;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        PrintWriter writer = new PrintWriter(
                new BufferedWriter(
                        new FileWriter("badmilk.out")
                    )
            );
        writer.println(String.valueOf(maxDose));
        writer.close();
    }
    
    static int[] scan(Scanner sc, String seperator) {
        String scan = sc.nextLine();
        String[] temp = scan.split(seperator);
        int[] out = new int[temp.length];
        for (int i = 0; i < temp.length; i++) {
            out[i] = Integer.parseInt(temp[i]);
        }
        return out;
    }
    static int[] scan (Scanner sc) {
        return scan(sc, " ");
    }
}
