package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/21
 */
public class Q36ValidSudoku {
    public static void main(String[] args) {
        char[][] board = {
                {'1', '.', '.', '.', '.', '.', '.', '.', '.' },
                {'.', '2', '.', '.', '.', '.', '.', '.', '.' },
                {'.', '.', '3', '.', '.', '.', '.', '.', '.' },
                {'.', '.', '.', '4', '.', '.', '.', '.', '.' },
                {'.', '.', '.', '.', '5', '.', '.', '.', '.' },
                {'.', '.', '.', '.', '.', '6', '.', '.', '.' },
                {'.', '.', '.', '.', '.', '.', '7', '.', '.' },
                {'.', '.', '.', '.', '.', '.', '.', '8', '.' },
                {'.', '.', '.', '.', '.', '.', '.', '.', '9' }
        };
        System.out.println(isValidSudoku(board));
    }

    public static boolean isValidSudoku(char[][] board) {
        int rows = board.length;
        if (rows != 9) return false;

        for (int row = 0; row < rows; row++) {
            int cols = board[row].length;
            if (cols != 9) return false;

            int[] flag = new int[9];
            for (int col = 0; col < cols; col++) {
                if (board[row][col] != '.') {
                    if (board[row][col] < 49 || board[row][col] > 57)
                        return false;
                    if (flag[board[row][col] - 49] == 1)
                        return false;
                    flag[board[row][col] - 49] = 1;
                }
            }
        }

        for (int col = 0; col < 9; col++) {
            int[] flag = new int[9];
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.') {
                    if (flag[board[row][col] - 49] == 1)
                        return false;
                    flag[board[row][col] - 49] = 1;
                }
            }
        }

        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                int rs = i + 2;
                int cs = j + 2;
                int[] flag = new int[9];
                for (int row = i; row <= rs; row++) {
                    for (int col = j; col <= cs; col++) {
                        if (board[row][col] != '.') {
                            if (flag[board[row][col] - 49] == 1)
                                return false;
                            flag[board[row][col] - 49] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
}
