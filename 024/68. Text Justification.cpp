class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;

        int i = 0;
        while (i < words.size())
        {
            int j = i;
            int sum = 0;

            // find how many words fit
            while (j < words.size() && sum + words[j].size() + (j - i) <= maxWidth)
            {
                sum += words[j].size();
                j++;
            }
            j--;

            int extra = maxWidth - (sum + (j - i));
            int amount, rem;
            bool flag = false;

            if (j - i == 0)
            {
                amount = 0;
                rem = 0;
                flag = true;
            }
            else
            {
                amount = extra / (j - i) + 1;
                rem = extra % (j - i);
            }

            string line = "";
            for (int s = i; s <= j; s++)
            {
                line += words[s];

                if (s < j)
                {
                    if (j != words.size() - 1)
                    {
                        line += string(amount + (rem > 0 ? 1 : 0), ' ');
                    }
                    else
                    {
                        line += ' ';
                    }
                    rem = max(0, rem - 1);
                }
            }

            if (j == words.size() - 1)
                line += string(maxWidth - line.size(), ' ');

            if (flag)
                line += string(maxWidth - line.size(), ' ');

            ans.push_back(line);
            i = j + 1;
        }

        return ans;
    }
};