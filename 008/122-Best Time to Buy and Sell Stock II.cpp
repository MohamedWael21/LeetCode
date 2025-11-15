class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            if(mi < prices[i]){
                profit += prices[i]-mi;
                mi = prices[i];
            }
            mi = min(mi, prices[i]);
        }

        return profit;
    }
};i