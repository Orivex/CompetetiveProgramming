import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class GrayCodeSolution2 {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();

        List<String> solution = generate(n);
        for (String s : solution) {
            System.out.println(s);
        }
    }

     static List<String> generate(int n) {
        if(n==1) {
            List<String> grayCode = new ArrayList<>();
            grayCode.add("1");
            grayCode.add("0");
            return grayCode;
        }

        List<String> prevGrayCode = generate(n-1);
        List<String> reversedPrevGrayCode = new ArrayList<>(prevGrayCode);
         Collections.reverse(reversedPrevGrayCode);
        List<String> currentGrayCode = new ArrayList<>(prevGrayCode);

         for (int i = 0; i < prevGrayCode.size(); i++) {
             currentGrayCode.set(i, "0" + prevGrayCode.get(i));
             prevGrayCode.set(i, "1" + reversedPrevGrayCode.get(i));
         }

         currentGrayCode.addAll(prevGrayCode);

         return currentGrayCode;
     }
}
