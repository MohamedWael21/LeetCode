class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> mp1, mp2;
        for (char c : ransomNote)
        {
            mp1[c]++;
        }
        for (char c : magazine)
        {
            mp2[c]++;
        }
        for (auto ele : mp1)
        {
            if (mp2[ele.first] < ele.second)
                return false;
        }
        return true;
    }
};