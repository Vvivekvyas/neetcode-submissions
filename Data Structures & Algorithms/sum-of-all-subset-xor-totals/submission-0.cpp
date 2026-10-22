class Solution {
public:
    void solve(vector<int>& nums,int& ans,int xr ,int i){
        if(i == nums.size()){
            ans += xr;
            return;
        }

        solve(nums,ans,xr ^ nums[i],i+1);
        solve(nums,ans,xr,i+1);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(nums,ans,0,0);
        return ans;
    }
};