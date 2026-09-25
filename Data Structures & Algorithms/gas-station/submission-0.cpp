class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0;

        for(auto x : gas){
            totalgas += x;
        }
        for(auto x : cost){
            totalcost += x;
        }

        if(totalgas < totalcost){
            return -1;
        }

        int currgas = 0;
        int start = 0;
        for(int i=0 ; i<gas.size() ; i++){
            currgas += gas[i] - cost[i];

            if(currgas < 0){
                currgas = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
