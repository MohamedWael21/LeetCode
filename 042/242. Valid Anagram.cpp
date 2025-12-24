class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> mp;
        if (s.size() != t.size())
            return false;
        for (char c : s)
        {
            mp[c]++;
        }
        for (char c : t)
        {
            if (mp.find(c) == mp.end())
                return false;
            if (mp[c] == 0)
                return false;
            mp[c]--;
        }

        return true;
    }
};