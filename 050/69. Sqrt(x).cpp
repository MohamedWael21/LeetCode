class Solution
{
public:
    int mySqrt(int x)
    {

        long long l = 0, r = x;
        long long ans = -1;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            if (mid * mid == x)
            {
                ans = mid;
                break;
            }
            else if (mid * mid > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (ans == -1)
            ans = r;

        return ans;
    }
};
