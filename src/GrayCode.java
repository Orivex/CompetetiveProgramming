import java.util.*;

public class GrayCode {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();

        Set<String> bitStrings = new HashSet<>();

        for (int i = 1; i < Math.pow(2, n); i++) {

            StringBuilder bitString = new StringBuilder();
            bitString.append(Integer.toBinaryString(i));

            if(bitString.length() < n) {
                bitString.insert(0, "0".repeat( n-bitString.length()));
            }

            bitStrings.add(bitString.toString());
        }

        List<String> grayCode = new ArrayList<>();

        StringBuilder previous = new StringBuilder();
        previous.append("0".repeat(n));

        grayCode.add(previous.toString());

        while (!bitStrings.isEmpty()) {

            StringBuilder next = new StringBuilder();

            for (int i = n-1; i >= 0; i--) {
                next.append(previous);

                if(next.charAt(i) == '0') {
                    next.setCharAt(i, '1');
                }
                else {
                    next.setCharAt(i, '0');
                }

                if(bitStrings.contains(next.toString())){
                    grayCode.add(next.toString());
                    bitStrings.remove(next.toString());
                    previous = next;
                    break;
                }
                else {
                    next.delete(0, next.length());
                }
            }
        }

        for (String code : grayCode) {
            System.out.println(code);
        }
    }
}
