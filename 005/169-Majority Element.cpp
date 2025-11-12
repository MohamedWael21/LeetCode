class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = 0, maj = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maj == 0)
            {
                res = nums[i];
            }
            if (res == nums[i])
                maj++;
            else
                maj--;
        }

        return res;
    }
};