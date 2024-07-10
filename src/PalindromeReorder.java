import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class PalindromeReorder {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String n = in.nextLine();

        HashMap<Character, Integer> map = new HashMap<>();

        for (char ch : n.toCharArray()) {
            if(!map.containsKey(ch)) {
                map.put(ch, 1);
            }
            else {
                map.put(ch, map.get(ch)+1);
            }
        }

        StringBuilder palindrome1 = new StringBuilder();
        char oddChar = ' ';
        int oddInt = 0;

        for(Map.Entry<Character, Integer> entry : map.entrySet()) {
            if(entry.getValue() % 2 == 1) {

                if(oddChar != ' ') {
                    System.out.println("NO SOLUTION");
                    return;
                }

                oddInt = entry.getValue();
                oddChar = entry.getKey();

                continue;
            }

            palindrome1.append(String.valueOf(entry.getKey()).repeat(Math.max(0, entry.getValue() / 2)));

        }


        String palindrome2 = new StringBuilder(palindrome1).reverse().toString();

        palindrome1.append(String.valueOf(oddChar).repeat(oddInt));

        palindrome1.append(palindrome2);
        System.out.println(palindrome1);

    }
}
