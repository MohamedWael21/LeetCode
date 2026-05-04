class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>hp(nums.begin(), nums.end());
        int curr = 0;
        while(k--){
            curr = hp.top();
            hp.pop();
        }
        return curr;
    }
};
