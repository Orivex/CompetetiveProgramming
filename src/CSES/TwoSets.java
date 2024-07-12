import java.util.Scanner;

public class TwoSets {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        boolean possible =  ( ( (n * (n+1) ) / 2 ) % 2) == 0 ? true: false;

        StringBuilder stringBuilder = new StringBuilder();

        if(!possible) {
            System.out.println("NO");
            return;
        }

        stringBuilder.append("YES" + "\n");

        int odd = n % 2 == 1 ? 1: 0;

        stringBuilder.append((int) Math.ceil((double) n / 2) + "\n");

        for (int i = 1; i <= (int) Math.ceil((double) (n-odd) / 2); i+=2) {
            stringBuilder.append(i + " ");
            stringBuilder.append((n+1-odd)-i + " ");
        }

        stringBuilder.append("\n");
        stringBuilder.append((int) Math.ceil((double) n / 2 - odd) + "\n");

        for (int i = 2; i <= (int) Math.ceil((double) (n-odd) / 2); i+=2) {
            stringBuilder.append(i + " ");
            stringBuilder.append((n+1-odd)-i + " ");
        }

        if(odd == 1)
            stringBuilder.append(n);

        System.out.println(stringBuilder);

    }
}
