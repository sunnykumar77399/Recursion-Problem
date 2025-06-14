// 🚀 Thinking Approach:

// Goal:    Place N queens on an N x N chessboard such that no two queens attack each other.  Queens can attack row-wise, column-wise, and diagonally.
// Key Ideas:    Use recursion and try placing a queen column by column.
//               At each column, try all rows.
//               Before placing a queen at (row, col), check:
//               Is the row empty? (LeftRow)
//               Is the upper diagonal empty? (UDiagonal)
//               Is the lower diagonal empty? (LDiagonal)
//               If safe, place the queen and move to the next column.
//               After recursion, backtrack by removing the queen (restore the board).

// Optimizations:  LeftRow, LDiagonal, UDiagonal are used to track safety in O(1) time.
//                 Total time complexity is roughly O(N!) in the worst case.


class Solution {
public:
    vector<vector<string>> res;
 
    void func(int col, vector<string>& board, vector<int>& LeftRow,
              vector<int>& LDiagonal, vector<int>& UDiagonal,int n) {
        if (col==n) {
            res.push_back(board);
            return ;
        }
        for (int row = 0; row < n; row++) {
            if (LeftRow[row]==0 && UDiagonal[n-1+col-row]==0 && LDiagonal[row+col]==0) {
                board[row][col] = 'Q';
                LeftRow[row]=1;
                LDiagonal[row+col]=1;
                UDiagonal[n-1+col-row]=1; 
                func(col+1, board, LeftRow, LDiagonal, UDiagonal,n);
                board[row][col] = '.';
                LeftRow[row]=0;
                LDiagonal[row+col]=0;
                UDiagonal[n-1+col-row]=0; 
            }
        } 
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0);
        vector<int> LDiagonal(2 * n - 1, 0);
        vector<int> UDiagonal(2 * n - 1, 0);
        func(0, board, leftRow, LDiagonal, UDiagonal,n);
        return res;
    }
};
