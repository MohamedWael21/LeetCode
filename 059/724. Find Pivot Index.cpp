class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>prefix(nums.size(), 0);
        vector<int>suffix(nums.size(), 0);
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        for(int j=nums.size()-2; j>=0; j--){
            suffix[j] = nums[j] + suffix[j+1];

        }

        for(int i=0; i<nums.size(); i++){
            int left = 0;
            int right = 0;
            if(i-1>=0) left += prefix[i-1];
            if(i+1 <nums.size()) right += suffix[i+1];
            if(left == right) return i;
        }

        return -1;
    }
};
