class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        map<string, int> mp;
        for (auto word : words)
            mp[word]++;
        int t = words.size();
        int sz = words[0].size();
        vector<int> ans;

        for (int offset = 0; offset < sz; offset++)
        {
            map<string, int> curr;
            int cnt = 0;
            int i = offset, j = offset;
            while (j < s.size())
            {
                if (j + sz > s.size())
                    break;
                string word = s.substr(j, sz);
                if (!mp[word])
                {
                    j += sz;
                    curr.clear();
                    cnt = 0;
                    i = j;
                    continue;
                }
                if (mp[word] >= curr[word] + 1)
                {
                    curr[word]++;
                    cnt++;
                    j += sz;
                }
                else
                {
                    curr[word]++;
                    cnt++;
                    while (i < j && curr[word] > mp[word])
                    {
                        curr[s.substr(i, sz)]--;
                        cnt--;
                        i += sz;
                    }
                    j += sz;
                }
                if (cnt == t)
                {
                    ans.push_back(i);
                    curr[s.substr(i, sz)]--;
                    cnt--;
                    i += sz;
                }
            }
        }

        return ans;
    }
};