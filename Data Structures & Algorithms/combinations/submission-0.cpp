class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int>& temp,int n,int k,int i){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        if(i > n) return;

        temp.push_back(i);
        solve(ans,temp,n,k,i+1);
        temp.pop_back();
        solve(ans,temp,n,k,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,n,k,1);
        return ans;
    }
};