class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {

            if (token == "+") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                st.push(val2 + val1);
            }

            else if (token == "-") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                st.push(val2 - val1);
            }

            else if (token == "*") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                st.push(val2 * val1);
            }

            else if (token == "/") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                st.push(val2 / val1);
            }

            else {
                // token is a number
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};