import java.util.Scanner;

public class IncreasingArray {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long n = in.nextInt();

        long previous = in.nextInt();
        long moves = 0;

        for (int i = 1; i < n; i++) {
            long next = in.nextInt();

            if(next > previous) {
                previous = next;
                continue;
            }

            moves += previous-next;
        }

        System.out.println(moves);
    }
}
