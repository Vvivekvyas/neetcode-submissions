class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        int ans = 0;
        for(int i=0 ; i < nums.size() ; i++){
            if(mp.find(nums[i] - 1) == mp.end()){
                int start = nums[i];
                int count = 1;

                while(mp.find(start + 1) != mp.end()){
                    count++;
                    start++;
                }
            ans = max(ans,count);
            }
        }
        return ans;
    }
};
