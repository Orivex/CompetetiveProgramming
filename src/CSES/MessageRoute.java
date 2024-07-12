import java.util.*;

public class MessageRoute {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        int[][] adjList = new int[n+1][n+1];

        for (int i = 0; i < m; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            adjList[a][b]++;
            adjList[b][a]++;
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        int[] visited = new int[n+1];
        visited[1] = 1;
        int[] parent = new int[n+1];

        while (!q.isEmpty()) {
            int current = q.poll();

            for (int i = 1; i < adjList.length; i++) {
                if(visited[i] == 0 && adjList[current][i] > 0){
                    visited[i] = 1;
                    parent[i] = current;
                    q.add(i);
                }
            }
        }

        Stack<Integer> route = new Stack<>();
        int current = n;

        if(parent[n] == 0) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        while (current != 0) {
            route.push(current);
            current = parent[current];
        }

        System.out.println(route.size());
        while (!route.isEmpty()) {
            System.out.print(route.pop() + " ");
        }

    }
}
