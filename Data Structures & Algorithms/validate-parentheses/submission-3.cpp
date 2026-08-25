class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                // Check before st.top()
                if(st.empty()) {
                    return false;
                }

                if((ch == ')' && st.top() == '(') ||
                   (ch == ']' && st.top() == '[') ||
                   (ch == '}' && st.top() == '{')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};