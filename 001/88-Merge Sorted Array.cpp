#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    vector<int> tmp(n + m);
    int cnt = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            tmp[cnt++] = nums1[i++];
        }
        else
        {
            tmp[cnt++] = nums2[j++];
        }
    }

    while (i < m)
    {
        tmp[cnt++] = nums1[i++];
    }
    while (j < n)
    {
        tmp[cnt++] = nums2[j++];
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = tmp[i];
    }
}

int main()
{

    return 0;
}