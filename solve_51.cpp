//经典的N皇后问题
//依然是套用回溯法的模板
//唯一的变化处理就是可以整体保留棋盘数组，当然也可以分段来
//操作部分就是当前局面的合法化验证

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
           vector<vector<string>>  res;
           vector<string> board(n, string(n,  '.'));
           backtrack(res, board, 0);
           return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& board, int row){
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col =0; col <n; col++) {
            if (!isvalid(board, row, col)){
                continue;
            }
            board[row][col] = 'Q';
            backtrack(res, board, row+1);
            board[row][col] = '.';
        }
    }
    bool isvalid(vector<string>& board, int row, int col){
        int n = board.size();
        // 检查同列是否有冲突
        for (int i= 0; i<row; i++){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        //检查左上方斜线冲突
        for(int i = row -1, j = col -1; i>=0&& j>=0; i--,j--){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        //检查右上方斜线冲突
        for(int i = row -1, j = col +1; i>=0 && j <n ; i--, j++ ){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};
