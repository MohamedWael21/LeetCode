class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> original(52, 0), curr(52, 0);
        for (char c : t)
        {
            if (isupper(c))
                original[c - 'A' + 26]++;
            else
                original[c - 'a']++;
        }

        auto check = [&]()
        {
            for (int i = 0; i < 52; i++)
            {
                if (curr[i] < original[i])
                    return false;
            }
            return true;
        };

        int i = 0, j = 0;
        int bestLen = INT_MAX;
        int bestL = 0;

        while (j < s.size())
        {
            if (isupper(s[j]))
                curr[s[j] - 'A' + 26]++;
            else
                curr[s[j] - 'a']++;

            while (check())
            {
                if (j - i + 1 < bestLen)
                {
                    bestLen = j - i + 1;
                    bestL = i;
                }

                if (isupper(s[i]))
                    curr[s[i] - 'A' + 26]--;
                else
                    curr[s[i] - 'a']--;
                i++;
            }
            j++;
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};
