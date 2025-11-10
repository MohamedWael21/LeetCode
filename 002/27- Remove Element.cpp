#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        if (nums[r] != val)
        {
            while (nums[l] != val && l < nums.size() - 1 && l <= r)
            {
                k++;
                l++;
            }
            if (l <= r)
            {
                swap(nums[r], nums[l++]);
                k++;
            }
        }
        r--;
    }

    if (l == r && nums[l] != val)
    {
        k++;
    }
    return k;
}

int main()
{
}