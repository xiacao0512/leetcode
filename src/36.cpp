// by watercolor, 2022/09/10

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> row, column, square;

        for(int i = 0; i < 9; i++) {
            row.clear();
            column.clear();
            square.clear();
            
            for(int j = 0; j < 9; j++) {
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    if(row.find(board[i][j]) == row.end()) {
                        row.insert(board[i][j]);
                    } else {
                        return false;
                    }
                }

                if(board[j][i] >= '0' && board[j][i] <= '9') {
                    if(column.find(board[j][i]) == column.end()) {
                        column.insert(board[j][i]);
                    } else {
                        return false;
                    }
                }

                int i2 = (i/3)*3+j/3;
                int j2 = (i%3)*3+j%3;
                if(board[i2][j2] >= '0' && board[i2][j2] <= '9') {
                    if(square.find(board[i2][j2]) == square.end()) {
                        square.insert(board[i2][j2]);
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
