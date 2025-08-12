import java.util.Scanner;

public class CoinPile {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < t; i++) {
            int a = in.nextInt();
            int b = in.nextInt();

            if((a+b)%3 == 0 && 2*Math.min(a, b)>=Math.max(a, b))
                stringBuilder.append("YES \n");
            else
                stringBuilder.append("NO \n");
        }

        System.out.println(stringBuilder);
    }
}
