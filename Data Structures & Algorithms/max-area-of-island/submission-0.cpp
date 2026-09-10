class Solution {
public:
    int dfs(vector<vector<int>>& grid,int row,int col){
        int n = grid.size();
        int m = grid[0].size();

          if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0){
            return 0;
          }

          grid[row][col] = 0;
          int area = 1;
          area += dfs(grid,row + 1,col);
          area += dfs(grid,row - 1,col);
          area += dfs(grid,row,col + 1);
          area += dfs(grid,row,col - 1);
          
          return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxarea = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == 1){
                    int area = dfs(grid,row,col);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};
