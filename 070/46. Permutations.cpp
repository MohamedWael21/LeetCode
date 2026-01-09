class Solution {
    void sv(vector<int>&curr, vector<int>&nums, vector<vector<int>>&ans, unordered_set<int>&st){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
        }
        for(int j=0; j<nums.size(); j++){
            if(st.count(nums[j]))continue;
            curr.push_back(nums[j]);
            st.insert(nums[j]);
            sv(curr, nums, ans, st);
            curr.pop_back();
            st.erase(nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        unordered_set<int>st;
        sv(curr, nums, ans, st);

        return ans;   
    }
};
