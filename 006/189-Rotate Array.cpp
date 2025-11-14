class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        auto rev = [&](int l, int r)
        {
            while (l < r)
            {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        };
        rev(0, nums.size() - 1);
        rev(0, k - 1);
        rev(k, nums.size() - 1);
    }
};