class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1 ; i<strs.size() ; i++){
            string curr = strs[i];
            int j = 0;
            while(j < curr.length() && j < prefix.length() && prefix[j] == curr[j]){
                j++;
            }
            prefix = prefix.substr(0,j);
            if(prefix == "") return "";
        }
        return prefix;
    }
};