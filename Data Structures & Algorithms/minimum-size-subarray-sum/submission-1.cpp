class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int ans = INT_MAX;
        int sum = 0;

        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(i - left + 1 , ans);
                sum -= nums[left];
                left++;
            }
        }
      return ans == INT_MAX ? 0 : ans;
    }
};