class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        for(int msk=0; msk<(1<<nums.size()); msk++){
            vector<int>subset; 
            for(int i=0; i<nums.size(); i++){
                if(msk&(1<<i)){
                    subset.push_back(nums[i]);
                }
            }   
            ans.push_back(subset);
        }

        return ans;
    }
};
