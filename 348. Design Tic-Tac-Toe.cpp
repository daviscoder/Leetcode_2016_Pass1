class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    int size;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->rows.resize(n);
        this->cols.resize(n);
        diagonal = 0;
        antiDiagonal = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int toAdd = player == 1? 1 : -1;
        rows[row] += toAdd;
        cols[col] += toAdd;
        diagonal += row == col? toAdd : 0;
        antiDiagonal += row == size - 1 - col? toAdd : 0;
        if (abs (rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || abs(antiDiagonal) == size)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
