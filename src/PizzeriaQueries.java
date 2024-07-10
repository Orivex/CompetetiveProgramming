import java.util.Scanner;

public class PizzeriaQueries {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        int[] price = new int[n];
        for (int i = 0; i < n; i++) {
            price[i] = scanner.nextInt();
        }

        getMinimum(price, 0, 4, 0, 8);

    }

    static int getMinimum(int[] price, int a, int b, int low, int high) {

        if(low == high-1) {
            return price[a] + Math.abs(a-b);
        }

        int mid = (low+high)/2;
        int val1 = getMinimum(price, a, b, low, mid);
        int val2 = getMinimum(price, a, b, mid, high);

        return Math.min(val1, val2);
    }

}
