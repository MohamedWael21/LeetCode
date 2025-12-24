class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> mp;
        for (string s : strs)
        {
            string temp = s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
        }

        vector<vector<string>> ans;
        for (auto ele : mp)
        {
            ans.push_back(ele.second);
        }

        return ans;
    }
};