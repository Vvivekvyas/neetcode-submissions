class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int left = 0;
        int right = 1;
        int maxprofit = 0;

        while(right < n){
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                maxprofit = max(maxprofit,profit);
            }
            else{
                left = right;
            }
            right++;
        }
return maxprofit;

    }
};
