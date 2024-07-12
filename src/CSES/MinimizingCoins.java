import java.util.Scanner;

public class MinimizingCoins {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int x = in.nextInt();
        int[] coins = new int[n];

        for (int i = 0; i < n; i++) {
            coins[i] = in.nextInt();
        }

        System.out.println(solve(x, coins));

    }

    static long solve(int x, int[] coins) {

        int[] minimum = new int[x+1];
        minimum[0] = 0;


        for (int i = 1; i < minimum.length; i++) {
            minimum[i] = Integer.MAX_VALUE;
        }

        for (int i = 1; i <= x; i++) {

            for (int coin : coins) {
                if (i >= coin) {
                    int min = Math.min(minimum[i - coin], minimum[i]);

                    if (min != Integer.MAX_VALUE) {
                        minimum[i] = Math.min(min + 1, minimum[i]);
                    }
                }
            }

        }

        return minimum[x] == Integer.MAX_VALUE ? -1: minimum[x];

    }
}
