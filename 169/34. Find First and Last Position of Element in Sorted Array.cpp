class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     auto it1 = lower_bound(nums.begin(), nums.end(), target);   
     auto it2 = upper_bound(nums.begin(), nums.end(), target);
     int sz =  it2-it1 - 1;
     if(sz < 0) return {-1, -1};
     int st = it1 - nums.begin();
     int end = st + sz;
     return {st, end};
    }
};
