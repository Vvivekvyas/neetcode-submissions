class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans,int target,int i){
         if(target == 0){
            ans.push_back(temp);
            return;
         }

           if(i == nums.size())
            return;

         if(nums[i] <= target){
            temp.push_back(nums[i]);
            solve(nums,temp,ans,target - nums[i],i);
            temp.pop_back();
         }
         solve(nums,temp,ans,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        solve(nums,temp,ans,target,0);
        return ans;
    }
};
