class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int p1 = 0;
        int p2 = 0;
        string ans = "";
        while(p1 < n || p2 < m){
            if(p1 < n){
              ans.push_back(word1[p1]);
              p1++;
            }
            if(p2 < m){
                ans.push_back(word2[p2]);
                p2++;
            }
        }
        return ans;
    }
};