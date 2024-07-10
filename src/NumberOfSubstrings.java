import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class NumberOfSubstrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.nextLine();

        int n = s.length();
        System.out.println(n * (n + 1) / 2);

        Set<String> substrings = new HashSet<>();

        for (int i = 0; i < s.length(); i++) {
            for (int j = i+1; j < s.length()+1; j++) {
                substrings.add(s.substring(i, j));
            }
        }

        System.out.println(substrings.size());

    }
}
