class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (i < nums.size())
        {
            while (j < nums.size() && sum < target)
            {
                sum += nums[j];
                j++;
            }
            if (j >= nums.size() && sum < target)
                break;
            while (sum >= target)
            {
                ans = min(ans, j - i);
                sum -= nums[i];
                i++;
            }
        }
        if (ans == INT_MAX)
            return 0;
        else
            return ans;
    }
};