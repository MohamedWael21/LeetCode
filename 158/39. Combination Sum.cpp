class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        function<void(int, int, vector<int>&)> sv = [&](int curr, int start, vector<int>&comb){
            if(curr > target) return;
            if(curr == target){
                ans.push_back(comb);
                return;
            }
            for(int i=start; i<candidates.size(); i++){
                comb.push_back(candidates[i]);
                sv(curr+candidates[i], i, comb);
                comb.pop_back();
            }
        };
        vector<int>comb;
        sv(0, 0, comb);
        return ans;
    }
};
