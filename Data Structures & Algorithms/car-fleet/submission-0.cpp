class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;

        for (int x = 0; x < n; x++) {
            cars.push_back({position[x], speed[x]});
        }

        // Sort by position in descending order
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for (auto [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};