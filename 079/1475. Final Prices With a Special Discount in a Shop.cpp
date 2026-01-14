class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size());
        stack<int>st;
        for(int i=prices.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() > prices[i])st.pop();
            int discount = st.empty() ? 0 : st.top();
            ans[i] = prices[i]-discount;
            st.push(prices[i]);
        }
        return ans;
      
    }
};