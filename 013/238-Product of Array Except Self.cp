class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int product = 1;
        int zeroCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                product *= nums[i];
            }
            if(nums[i] == 0) zeroCnt++;
        }   
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0 && zeroCnt < 2){
                ans[i] = product;
            }else if(zeroCnt == 1){
                ans[i] = 0;
            }else if(zeroCnt == 0){
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};