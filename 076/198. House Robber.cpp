class Solution {
    
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>dp(nums.size()+1, 0);
        // function<int(int)> sv = [&](int i){
        //     if(i >= nums.size()) return 0;
        //     int &ret  = dp[i];
        //     if(~ret) return ret;
        //     ret = max(ret, sv(i+1));
        //     ret = max(ret, sv(i+2)+nums[i]);
        //     return ret;
        // };
        // dp[0] = nums[0];
        // dp[1] = max(dp[0], nums[1]);
        // for(int i=2; i<nums.size(); i++){
        //     dp[i] = max(dp[i], dp[i-1]);
        //     dp[i] = max(dp[i], dp[i-2]+nums[i]);
        // }
        // return dp[nums.size()-1];
        int prev2 = nums[0];
        int prev1 = max(prev2, nums[1]);
        for(int i=2; i<nums.size(); i++){
            int ans = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }
};
