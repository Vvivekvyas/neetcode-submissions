class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int req = t.length();
        int start = 0;
        int left = 0;
        int len = INT_MAX;

        vector<int>count(128,0);
        for(char ch : t){
            count[ch]++;
        }

        for(int right = 0; right < n ; right++){
            if(count[s[right]] > 0){
                req--;
            }
            count[s[right]]--;

            while(req == 0){
                if(right - left + 1 < len){
                    len = min(len,right - left + 1);
                    start = left;
                }

                count[s[left]]++;
                if(count[s[left]] > 0){
                    req++;
                }
                left++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};
