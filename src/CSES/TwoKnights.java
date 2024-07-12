import java.util.Scanner;

public class TwoKnights {
    public static void main(String[] args) {

        long n = new Scanner(System.in).nextLong();

        for (long k = 1; k <= n; k++) {

            System.out.println( (long) ( Math.pow(k, 2) * (Math.pow(k, 2) - 1) ) / 2 - 4 * (k-1) * (k-2)  );

        }
    }
}
