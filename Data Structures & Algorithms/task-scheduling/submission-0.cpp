class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        priority_queue<int>pq;
        for(int f : freq){
            if(f > 0){
                pq.push(f);
            }
        }

        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle = n + 1;

            while(cycle > 0 && !pq.empty()){
                int f = pq.top();
                pq.pop();
                f--;

                if(f > 0){
                    temp.push_back(f);
                }
                time++;
                cycle--;
            }

            for (int f : temp) {
                pq.push(f);
            }

             if (!pq.empty()) {
                time += cycle;
            }
        }
        return time;
    }
};
