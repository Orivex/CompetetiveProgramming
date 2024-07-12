import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class DigitQueries {
    public static void main(String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println(findIndex(in.nextLong()));
        }
    }

    static long findIndex(long k) {
        if(k <= 9) {
            return k;
        }

        long digitPositions = 0;
        long digits = 0;
        while(digits < k) {
            digits += (long) (digitPositions * Math.pow(10, digitPositions-1) * 9);
            digitPositions++;
        }
        digitPositions--;

        long upperBoundNumber = (long)Math.pow(10, digitPositions) - 1;

        long digitDistance = digits - k;

        long numberDistanceToUpperBound = digitDistance / digitPositions;

        long number = (upperBoundNumber - numberDistanceToUpperBound);

        long remainder = digitDistance % digitPositions;

        for (int i = 0; i < remainder; i++) {
            number /= 10;
        }

        return number % 10;
    }
}
