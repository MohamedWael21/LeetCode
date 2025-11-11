class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[k - 2] != nums[i])
            {
                nums[k++] = nums[i];
            }
        }
        if (nums.size() == 1)
            return 1;
        return k;
    }
};