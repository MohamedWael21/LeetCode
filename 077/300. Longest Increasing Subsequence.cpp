class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1));
     function<int(int, int)> sv = [&](int i, int prev){
        if(i > nums.size()) return 0;
        int &ret = dp[i][prev];
        if(~ret) return ret;
        ret = max(ret, sv(i+1, prev));
        if(prev == 0|| nums[prev-1]<nums[i-1])
            ret = max(ret, sv(i+1, i)+1);
        return ret;
     };   
     return sv(1, 0);
    }
};
