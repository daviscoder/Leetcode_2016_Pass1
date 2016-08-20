class Solution {
public:

    bool helper (vector<vector<char>>& board, string word, int cur, int i, int j, vector<vector<bool>>& visited) {
//        cout << i << "\t" << j << endl;
        if (cur == word.length() - 1)
            return true;
        visited[i][j] = true;
        bool flag = false;
        if (flag == false && i > 0 && visited[i - 1][j] == false && board[i - 1][j] == word[cur + 1])
            flag = helper (board, word, cur + 1, i - 1, j, visited);
        if (flag == false && i < board.size() - 1 && visited[i + 1][j] == false && board[i + 1][j] == word[cur + 1])
            flag = helper (board, word, cur + 1, i + 1, j, visited);
        if (flag == false && j > 0 && visited[i][j - 1] == false && board[i][j - 1] == word[cur + 1])
            flag = helper (board, word, cur + 1, i, j - 1, visited);
        if (flag == false && j < board[0].size() - 1 && visited[i][j + 1] == false && board[i][j + 1] == word[cur + 1])
            flag = helper (board, word, cur + 1, i, j + 1, visited);
        visited[i][j] = false;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        if (word.length() == 0 || board.size() == 0 || board[0].size() == 0)
            return false;
        if (word.length() > board.size() * board[0].size())
            return false;
        bool res = false;
        vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) 
            for (int j = 0; j < board[0].size(); j++) 
                if (res == false && board[i][j] == word[0])
                    res = helper (board, word, 0, i, j, visited);

        return res;
    }
};
