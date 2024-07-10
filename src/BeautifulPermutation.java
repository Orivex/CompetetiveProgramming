import java.util.Scanner;

public class BeautifulPermutation {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();

        if(n == 2 || n == 3) {
            System.out.println("NO SOLUTION");
            return;
        }

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 2; i <= n; i+=2) {
            stringBuilder.append(i + " ");
        }

        for (int i = 1; i <= n; i+=2) {
            stringBuilder.append(i + " ");
        }

        System.out.println(stringBuilder);
    }
}
