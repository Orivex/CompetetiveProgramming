import java.util.Scanner;

public class Repetitions {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String n = in.nextLine();

        int max = 0;
        char current = ' ';
        int count = 1;

        for (char ch : n.toCharArray()) {
            if(ch == current) {
                count++;
            }
            else {
                current = ch;
                max = Math.max(max, count);
                count = 1;
            }
        }

        System.out.println(Math.max(max, count));
    }
}
