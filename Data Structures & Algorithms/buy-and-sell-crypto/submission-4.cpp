class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprofit = prices[0];
        int maxprofit = 0;

        for(int i=0 ; i<prices.size() ; i++){
            if(prices[i] < minprofit){
                minprofit = prices[i];
            }

            int profit = prices[i] - minprofit;
            maxprofit = max(maxprofit , profit);
        }
        return maxprofit;
    }
};
