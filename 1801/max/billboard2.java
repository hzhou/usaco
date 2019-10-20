//Max Yang
//45 minutes
//8 tests passsed
//Used last week's concept of area, but still failed to find out the 2 remaining tests
import java.io.*;

public class billboard2{
        public static void main(String[] args)throws IOException{
                Scanner scan = new Scanner(new File("billboard.in"));
                int Ax1=scan.nextInt(), Ay1=scan.nextInt(), Ax2=scan.nextInt(), Ay2=scan.nextInt();
                int Bx1=scan.nextInt(), By1=scan.nextInt(), Bx2=scan.nextInt(), By2=scan.nextInt();

                int length=0;
                int max_x, max_y;

                int area = (Ax2-Ax1)*(Ay2-Ay1);
                if(By2>=Ay2&&By1<Ay1){
                       	area -= ((Math.min(Ax2, Bx2)-Math.max(Ax1, Bx1))*(Math.min(Ay2, By2)-Math.max(Ay1, By1)));
                }

                System.out.println(area);
                if(area<0) area=0;

                PrintWriter out = new PrintWriter(new BufferedWriter (new FileWriter("billboard.out")));
                out.println(area);
                out.close();
        }
}