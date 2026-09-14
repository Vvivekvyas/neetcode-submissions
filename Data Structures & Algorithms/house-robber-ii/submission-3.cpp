class Solution {
public:
    int solve(vector<int>& nums,int start,int end,vector<int>& dp){
        if(start < end){
            return 0;
        }

        if(dp[start] != -1) return dp[start];
        
        return dp[start] = max(nums[start] + solve(nums,start - 2,end,dp) , solve(nums,start - 1,end,dp));

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        if (n == 1)
            return nums[0];

        
        int case1 = solve(nums,n-1,1,dp1);
        int case2 = solve(nums,n-2,0,dp2);

        return max(case1 , case2);
    }
};
