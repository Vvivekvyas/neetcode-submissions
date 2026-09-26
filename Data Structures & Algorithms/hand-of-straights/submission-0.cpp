class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }

        unordered_map<int,int>freq;
        for(int x : hand){
            freq[x]++;
        }

        sort(hand.begin(),hand.end());

        for(int x : hand){
            if(freq[x] == 0){
                continue;
            }
            for(int i=0 ; i<groupSize ; i++){
                int curr = i+x;
                if(freq[curr] == 0){
                    return false;
                }
                freq[curr]--;
            }
        }
        return true;
    }
};
