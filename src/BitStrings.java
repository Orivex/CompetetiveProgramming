import java.util.Scanner;

public class BitStrings {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long n = in.nextLong();

        System.out.println( pow(2, n) );
    }

    static long MOD = 1000000007;

    static long pow(long a, long b) {
        long ans = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }

        return ans;
    }
}
