class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int mx = 0;
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);
        unordered_set<int> done;
        for (int num : nums)
        {
            if (done.count(num) > 0)
                continue;
            if (st.find(num - 1) == st.end())
            {
                done.insert(num);
                int cnt = 1;
                int curr = num;
                while (st.find(curr + 1) != st.end())
                {
                    cnt++;
                    curr = curr + 1;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};