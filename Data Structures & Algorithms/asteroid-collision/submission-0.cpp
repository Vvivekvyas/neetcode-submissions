class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {

            bool destroyed = false;

            // Collision is possible only when
            // stack top is moving right and current asteroid is moving left
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {

                if (abs(st.top()) == abs(asteroids[i])) {
                    st.pop();          // both explode
                    destroyed = true;
                    break;
                }
                else if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop();          // stack asteroid explodes
                    // continue checking with previous asteroid
                }
                else {
                    destroyed = true;  // current asteroid explodes
                    break;
                }
            }

            // Push current asteroid if it wasn't destroyed
            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};