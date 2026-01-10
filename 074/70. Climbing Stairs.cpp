class Solution {
    int sv(int i, int m, vector<int>&dp){
        if(i == m) return 1;
        if(i > m) return 0;
        int &ret = dp[i];
        if(~ret) return dp[i];
        ret = sv(i+1, m, dp) + sv(i+2, m, dp);
        return ret;
    }
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 0;
        for(int i=n-1; i>=0; i--){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
