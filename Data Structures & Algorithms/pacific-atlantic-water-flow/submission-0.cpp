class Solution {
public:
    int n;
    int m;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            if (vis[nr][nc])
                continue;

            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // Don't use int here!
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific: TOP
        for (int c = 0; c < m; c++) {
            dfs(0, c, heights, pacific);
        }

        // Pacific: LEFT
        for (int r = 0; r < n; r++) {
            dfs(r, 0, heights, pacific);
        }

        // Atlantic: BOTTOM
        for (int c = 0; c < m; c++) {
            dfs(n - 1, c, heights, atlantic);
        }

        // Atlantic: RIGHT
        for (int r = 0; r < n; r++) {
            dfs(r, m - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};