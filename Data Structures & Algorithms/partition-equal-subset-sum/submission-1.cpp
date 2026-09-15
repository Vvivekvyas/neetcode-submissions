class Solution {
public:
    bool solve(vector<int>& nums,int target , int i,vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }

        if(i >= nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];

        int take = 0;
        int nottake = 0;

        if(nums[i] <= target){
            take = solve(nums,target - nums[i],i+1,dp);
        }
        nottake = solve(nums,target,i+1,dp);

        return dp[i][target] = take + nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i=0 ; i<n ; i++){
            sum += nums[i];
        }

        vector<vector<int>>dp(n,vector<int>((sum / 2 ) + 1,-1));
        
        if(sum % 2 != 0) return false;

        return solve(nums,sum/2,0,dp);
    }
};
