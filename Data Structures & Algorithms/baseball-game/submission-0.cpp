class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int>st;

        for(int i=0 ; i<operations.size() ; i++){
            if(operations[i] == "D"){
                st.push(2*st.top());
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else if(operations[i] == "+"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                int sum = x1+x2;
                st.push(x1);
                st.push(sum);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};