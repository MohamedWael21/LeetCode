class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double curr = 0.0;
        for(int i=0;i<k; i++){
            curr+=nums[i];
        }

        double ans = curr;

        for(int i=k; i<nums.size(); i++){
            curr -= nums[i-k];
            curr += nums[i];
            ans = max(curr, ans);

        }


        return ans/k;
    }
};
