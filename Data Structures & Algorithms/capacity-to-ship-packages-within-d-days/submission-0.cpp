class Solution {
public:
    int findays(vector<int>& weights,int capacity){
        int load = 0;
        int day = 1;
        for(int i=0 ; i<weights.size() ; i++){
            if(weights[i] + load > capacity){
               day++;
               load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0); // 0 is initial value

        while(low <= high){
            int mid = low + (high - low)/2;
            int find = findays(weights,mid);
            if(find <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};