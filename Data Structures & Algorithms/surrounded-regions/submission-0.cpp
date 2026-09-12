class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        int n = board.size();
        int m = board[0].size();

        // Invalid cell or not an O
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') {
            return;
        }

         // Mark this O as safe
        board[i][j] = '#';

        // Down
        dfs(board, i + 1, j);

        // Up
        dfs(board, i - 1, j);

        // Right
        dfs(board, i, j + 1);

        // Left
        dfs(board, i, j - 1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        // first and last column
        for(int i=0 ; i<n ; i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);
            }

            if(board[i][m-1] == 'O'){
                dfs(board,i,m-1);
            }
        }
        // first row and last row
        for(int j=0 ; j<m ; j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j);
            }

            if(board[n-1][j] == 'O'){
                dfs(board,n-1,j);
            }
        }

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
