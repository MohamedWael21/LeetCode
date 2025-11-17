class Solution
{
public:
    vector<int> dp;
    int sv(int i, vector<int> &nums)
    {
        if (i >= nums.size() - 1)
            return 0;
        if (nums[i] == 0)
            return 1e5;
        if (~dp[i])
            return dp[i];
        int &ret = dp[i];
        ret = 1e7;
        for (int j = 1; j <= nums[i]; j++)
        {
            ret = min(ret, 1 + sv(i + j, nums));
        }
        return ret;
    }
    int jump(vector<int> &nums)
    {
        dp.resize(nums.size(), -1);
        return sv(0, nums);
    }
};