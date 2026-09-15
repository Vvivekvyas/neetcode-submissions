class Solution {
public:
    int solve(vector<int>& coins, int amount, int i,
              vector<vector<int>>& dp) {

        // Amount successfully formed
        if (amount == 0) {
            return 0;
        }

        // No coins left, but amount is still remaining
        if (i == coins.size()) {
            return 1e9;
        }

        // Already calculated
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }

        // Take current coin
        int take = 1e9;

        if (coins[i] <= amount) {
            take = 1 + solve(coins, amount - coins[i], i, dp);
        }

        // Don't take current coin
        int nottake = solve(coins, amount, i + 1, dp);

        return dp[i][amount] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, 0, dp);

        if (ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};