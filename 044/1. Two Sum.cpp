class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            auto it = mp.find(x);
            if (it == mp.end())
                continue;
            vector<int> indices = it->second;
            for (int j : indices)
            {
                if (i != j)
                    return {i, j};
            }
        }

        return {0, 0};
    }
};