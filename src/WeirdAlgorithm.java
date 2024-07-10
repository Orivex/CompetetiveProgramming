import java.util.Scanner;

public class WeirdAlgorithm {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long n = in.nextInt();

        System.out.print(n + " ");

        while (n != 1) {
            if(n % 2 == 1) {
                n = 1 + n * 3;
            }
            else {
                n /= 2;
            }

            System.out.print(n + " ");
        }
    }
}
