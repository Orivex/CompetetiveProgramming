import java.util.*;

public class AppleDivision {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        long[] values = new long[n];

        for (int i = 0; i < n; i++) {
            values[i] = in.nextInt();
        }

        System.out.println(solve(0, 0, values, 0));
    }

    static long solve(long group1, long group2, long[] values, int idx) {

        if(idx == values.length) {
            return Math.abs(group2-group1);
        }

        long difference1 = solve(group1+values[idx], group2, values, idx+1);
        long difference2 = solve(group1, group2+values[idx], values, idx+1);

        return Math.min(difference1, difference2);
    }
}
