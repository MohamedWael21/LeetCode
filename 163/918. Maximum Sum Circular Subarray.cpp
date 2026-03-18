class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0];
        int currMax = 0;
        int minSum = nums[0];
        int currMin = 0;
        for(int a : nums){
            currMax = max(currMax+a, a);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+a, a);
            minSum = min(minSum, currMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total-minSum) : maxSum;
    }
};
