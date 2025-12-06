class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int mx = 0;

        int l = 0;
        int r = height.size() - 1;
        while (l < r)
        {
            int amount = min(height[l], height[r]) * (r - l);
            mx = max(mx, amount);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return mx;
    }
};