import java.util.Scanner;

public class StaticRangeSumQueries {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int q = in.nextInt();

        int[] prefix = new int[n+1];
        prefix[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + in.nextInt();
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < q; i++) {

            int a = in.nextInt();
            int b = in.nextInt();

            result.append(prefix[b] - prefix[a - 1]).append("\n");

        }

        System.out.println(result);

    }
}
