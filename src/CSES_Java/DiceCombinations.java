import java.util.*;
import java.util.concurrent.TimeUnit;

public class DiceCombinations {
    static long MOD = 1000000007;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        System.out.println(solve(n));
    }

    static long solve(int n) {
        long[] combinations = new long[n+1];
        combinations[0] = 1;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= 6; j++) {

                if(i - j >= 0)
                    combinations[i] = (combinations[i] + combinations[i - j]) % MOD;

            }

        }

        return combinations[n];
    }
}
