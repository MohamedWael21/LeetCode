class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mi = prices[0];
        int pr = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            pr = max(pr, prices[i] - mi);
            mi = min(mi, prices[i]);
        }

        return pr;
    }
};