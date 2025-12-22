class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        map<string, char> mp;
        map<char, string> mp2;
        stringstream ss(s);
        vector<string> v;
        string value;
        while (ss >> value)
        {
            v.push_back(value);
        }
        if (pattern.size() != v.size())
            return false;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp2.find(pattern[i]) != mp2.end() && mp2[pattern[i]] != v[i])
                return false;
            if (mp.find(v[i]) != mp.end() && mp[v[i]] != pattern[i])
                return false;
            mp2[pattern[i]] = v[i];
            mp[v[i]] = pattern[i];
        }

        return true;
    }
};