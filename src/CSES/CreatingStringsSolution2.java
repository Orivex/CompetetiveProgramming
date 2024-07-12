import java.util.*;

public class CreatingStringsSolution2 {
    public static void main(String[] args) {
        String n = new Scanner(System.in).nextLine();
        char[] array = n.toCharArray();

        Set<String> solution = new HashSet<>();
        Arrays.sort(array);

        do {
            solution.add(new String(array));
        }
        while (nextPermutation(array));

        ArrayList<String> ordered_solution = new ArrayList<>(solution);
        Collections.sort(ordered_solution);

        System.out.println(solution.size());
        for (String s : ordered_solution) {
            System.out.println(s);
        }
    }

    static boolean nextPermutation(char[] array) {
        int i = array.length-2; //Pivot: Element before decreasing section

        while (i >= 0 && array[i] >= array[i+1]) {
            i--;
        }


        if(i < 0) {
            return false;
        }

        int j = array.length-1;

        while (array[j] <= array[i]) {
            j--;
        }

        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;

        //Reverse, to create decreasing section

        int start = i+1;
        int end = array.length-1;

        while (start < end) {
            char temp1 = array[start];
            array[start] = array[end];
            array[end] = temp1;
            start++;
            end--;
        }


        return true;
    }
}
