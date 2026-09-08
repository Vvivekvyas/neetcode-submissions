class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int i,int j,int index,vector<vector<bool>>& vis){
        if(index == word.size()){
            return true;
        }

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()){
            return false;
        }

        if(vis[i][j] == true){
            return false;
        }

        if(board[i][j] != word[index]){
            return false;
        }

        vis[i][j] = true;
        bool found = dfs(board,word,i + 1,j,index + 1,vis) ||
                     dfs(board,word,i - 1,j,index + 1,vis) ||
                     dfs(board,word,i,j + 1,index + 1,vis) ||
                     dfs(board,word,i,j - 1,index + 1,vis);
        vis[i][j] = false;
        return found;             
    }                
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board,word,i,j,0,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
