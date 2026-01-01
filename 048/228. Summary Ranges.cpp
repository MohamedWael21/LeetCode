class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;

        if (nums.size() == 0)
            return ans;

        auto create = [&](int start, int end)
        {
            if (start == end)
                ans.push_back(to_string(start));
            else
                ans.push_back(to_string(start) + "->" + to_string(end));
        };

        int start = nums[0];
        int end = nums[0];
        int prev = start;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - 1 == prev)
            {
                prev = nums[i];
                end = nums[i];
                continue;
            }
            else
            {
                create(start, end);
                start = nums[i];
                end = nums[i];
                prev = start;
            }
        }

        create(start, end);
        return ans;
    }
};