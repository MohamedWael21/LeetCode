class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;
        int mx = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (mx == 0)
                return false;
            mx--;
            mx = max(mx, nums[i]);
        }
        return true;
    }
};