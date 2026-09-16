class Solution {
public:
    int solve(vector<int>& nums, int target,int totalsum,int sum,int i,vector<vector<int>>& dp){
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        int idx = sum + totalsum; // handle negative cases 

        if(dp[i][idx] != -1) return dp[i][idx];

        int add = solve(nums,target,totalsum,sum + nums[i],i + 1,dp);
        int sub = solve(nums,target,totalsum,sum - nums[i],i + 1,dp);

        return dp[i][idx] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for(auto x : nums){
            totalsum += x;
        }

        if(target > totalsum || target < -totalsum){
            return 0;
        }

        vector<vector<int>>dp(nums.size(),vector<int>(2 * totalsum + 1 , -1)); // cover cases from -n to n 
        return solve(nums,target,totalsum,0,0,dp);
    }
};
