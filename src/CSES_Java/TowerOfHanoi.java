import java.util.Scanner;

public class TowerOfHanoi {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        System.out.println((int)Math.pow(2, n)-1);
        hanoi(n, 1, 3, 2);
    }

    static int count = 0;

    static void hanoi(int n, int start, int goal, int aux) {

        if(n==1) {
            System.out.println(start + " " + goal);
            return;
        }

        hanoi(n-1, start, aux, goal);
        System.out.println(start + " " + goal);
        hanoi(n-1, aux, goal, start);


    }
}
