class Solution
{
public:
    bool isHappy(int n)
    {
        auto calc = [&](int m)
        {
            int ans = 0;
            while (m > 0)
            {
                int digit = m % 10;
                ans += pow(digit, 2);
                m /= 10;
            }
            return ans;
        };

        map<int, bool> mp;
        while (true)
        {
            mp[n] = true;
            int next = calc(n);
            if (next == 1)
                return true;
            if (mp[next])
                break;
            n = next;
        }
        return false;
    }
};