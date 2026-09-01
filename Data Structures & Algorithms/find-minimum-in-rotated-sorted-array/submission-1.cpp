class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;

        while(left <= right){
            int mid = left + (right - left) / 2;

           if(nums[left] <= nums[mid]){
                ans = min(nums[left],ans);
                left = mid + 1;
            }
            else{
                right = mid - 1;
                ans = min(nums[mid],ans);
            }
        }
        return ans;
    }
};
