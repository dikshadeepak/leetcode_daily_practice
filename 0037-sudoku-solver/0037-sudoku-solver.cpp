class Solution {
public:

    bool valid(vector<vector<char>>& matrix, int row, int col, char x) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (matrix[row][j] == x)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (matrix[i][col] == x)
                return false;
        }

        // Check 3 x 3 box
        int initialRow = (row / 3) * 3;
        int initialCol = (col / 3) * 3;

        for (int i = initialRow; i < initialRow + 3; i++) {
            for (int j = initialCol; j < initialCol + 3; j++) {
                if (matrix[i][j] == x)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& matrix) {

        // Find empty cell
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (matrix[i][j] == '.') {

                    // Try 1 to 9
                    for (char c = '1'; c <= '9'; c++) {

                        if (valid(matrix, i, j, c)) {

                            // Choose
                            matrix[i][j] = c;

                            // Recurse
                            if (solve(matrix))
                                return true;

                            // Backtrack
                            matrix[i][j] = '.';
                        }
                    }

                    // No number worked
                    return false;
                }
            }
        }

        // No empty cell Sudoku solved
        return true;
    }

    void solveSudoku(vector<vector<char>>& matrix) {
        solve(matrix);
    }
};