import java.util.*;

public class CreatingStrings {
    public static void main(String[] args) {
        StringBuilder n = new StringBuilder();
        n.append(new Scanner(System.in).nextLine());

        Arrays.sort(n.toString().toCharArray());
        permute(new StringBuilder(), n);

        ArrayList<String> solution = new ArrayList<>(strings);
        Collections.sort(solution);

        System.out.println(solution.size());
        
        StringBuilder solutionBuilder = new StringBuilder();
        for (String s : solution) {
            solutionBuilder.append(s).append("\n");
        }
        
        System.out.println(solutionBuilder);

    }

    static Set<String> strings = new HashSet<>();
    static void permute(StringBuilder fixed, StringBuilder unfixed) {
        if(unfixed.length() == 1) {
            strings.add(fixed.toString()+unfixed);
            return;
        }

        for (int i = 0; i < unfixed.length(); i++) {
            char swap = unfixed.charAt(i);
            StringBuilder newFixed = new StringBuilder(fixed).append(swap);
            StringBuilder newUnfixed = new StringBuilder(unfixed).deleteCharAt(i);
            permute(newFixed, newUnfixed);
        }
    }
}
