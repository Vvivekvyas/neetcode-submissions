class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp{0,0,0};

        for(auto triplet : triplets){

            if(triplet[0] <= target[0] &&
               triplet[1] <= target[1] &&
               triplet[2] <= target[2]){

                 temp[0] = max(triplet[0],temp[0]);
                 temp[1] = max(triplet[1],temp[1]);
                 temp[2] = max(triplet[2],temp[2]);
               }
        }
        return temp == target;
    }
};
