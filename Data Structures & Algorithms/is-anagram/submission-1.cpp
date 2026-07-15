class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(128,0);

        for(char &x : s){
            freq[x - 'a']++;
        }
        for(char &x : t){
            freq[x - 'a']--;
        }

        for(auto &it : freq){
            if(it != 0){
                return false;
            }
        }
        return true;
    }
};
