class Solution {
public:
    bool solve(string &s1, string &s2, string &s3,int i,int j,vector<vector<int>>& dp){
        if(i == s1.length() && j == s2.length()) return true;

        int k = i + j;

        if(dp[i][j] != -1) return dp[i][j];

        if(i < s1.length() && s1[i] == s3[k]){
            if(solve(s1,s2,s3,i+1,j,dp)){
                return dp[i][j] = true;
            }
        }
        if(j < s2.length() && s2[j] == s3[k]){
            if(solve(s1,s2,s3,i,j+1,dp)){
               return dp[i][j] = true;
            }
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;

        int n = s1.length();
        int m = s2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(s1,s2,s3,0,0,dp);
    }
};
