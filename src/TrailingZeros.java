import java.math.BigInteger;
import java.util.Scanner;

public class TrailingZeros {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long n = in.nextLong();

        int count = 0;

        int power = 1;
        long next = (long) (n / Math.pow(5, power));

        while (next > 0) {
            count += next;
            power++;
            next = (long) (n / Math.pow(5, power));
        }

        System.out.println(count);
    }
}
