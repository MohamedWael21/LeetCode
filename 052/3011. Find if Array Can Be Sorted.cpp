class Solution {
public:
    bool canSortArray(vector<int>& nums) {
    
        auto same = [&](int a, int b){
            int cntA = 0, cntB = 0;
            for(int i=0; i<=8; i++){
                if((a>>i) &1)cntA++;
                if((b>>i) &1) cntB++;
            }
            return cntA == cntB;
        };

        for(int i=0; i<nums.size()-1; i++){
            bool isSwaped = false;
            for(int j=0; j<nums.size()-1; j++){
                if(same(nums[j], nums[j+1]) && nums[j] > nums[j+1]){
                    isSwaped = true;
                    swap(nums[j], nums[j+1]);
                }
            }
            if(!isSwaped) break;
        }
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};
