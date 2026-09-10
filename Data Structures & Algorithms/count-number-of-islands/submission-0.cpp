class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';
        dfs(grid,row + 1,col); 
        dfs(grid,row - 1,col); 
        dfs(grid,row,col + 1); 
        dfs(grid,row,col - 1); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1'){
                       ans++;
                       dfs(grid,row,col);
                }
            }
        }
        return ans;
    }
};
