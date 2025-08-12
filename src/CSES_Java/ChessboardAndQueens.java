import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ChessboardAndQueens {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);


        char[][] board = new char[8][8];

        for (int i = 0; i < 8; i++) {
            String line = in.nextLine();
            for (int j = 0; j < 8; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        solve(board, 0);

        System.out.println(solutions);

    }

    static int solutions = 0;
    static Set<Integer> usedColumns = new HashSet<>();
    static Set<Integer> posDiag = new HashSet<>();
    static Set<Integer> negDiag = new HashSet<>();

    static void solve(char[][] board, int row) {
        if(row == board.length) {
            solutions++;
            return;
        }

        for (int column = 0; column < 8; column++) {
            if(board[row][column] == '*' || usedColumns.contains(column) || posDiag.contains(row+column) || negDiag.contains(row-column))
                continue;

            usedColumns.add(column);
            posDiag.add(row+column);
            negDiag.add(row-column);

            solve(board, row+1);

            usedColumns.remove(column);
            posDiag.remove(row+column);
            negDiag.remove(row-column);
        }

    }
}
