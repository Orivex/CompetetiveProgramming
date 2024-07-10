import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class CompanyQueries {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int q = in.nextInt();

        int log = 0;

        while( (1 << log) <= n)
            log++;

        int[][] up = new int[n+1][log];

        int[] depth = new int[n+1];

        int[] parent = new int[n+1];

        for (int i = 2; i <= n; i++) {
            parent[i] = in.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            up[i][0] = parent[i];

            if(i != 1) {
                depth[i] = depth[parent[i]] + 1;
            }

            for (int j = 1; j < log; j++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        for (int i = 0; i < q; i++) {
            int x = in.nextInt();
            int k = in.nextInt();

            int current = x;

            if(depth[current] < k) {
                System.out.println(-1);
                continue;
            }

            for (int j = 0; j < log; j++) {
                if ( ( k & (1 << j) ) != 0 ) { //Check if bit j is on (try it out to understand) >_<
                    current = up[current][j];
                }
            }


            System.out.println(current);
        }

    }
}
