class Solution {
public:
    vector<vector<string>>ans;
    vector<string>temp;
    bool ispalindrome(string &s,int start , int end){
            while(start < end){
                if(s[start] != s[end]){
                    return false;
                }
                start++;
                end--;
            }
            return true;
       }
    void solve(string &s,int start){
         if(start == s.length()){
            ans.push_back(temp);
            return;
         }

         for(int end = start ; end < s.length() ; end++){
            if(ispalindrome(s,start,end)){
                temp.push_back(s.substr(start,end - start + 1));
                solve(s,end + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};
