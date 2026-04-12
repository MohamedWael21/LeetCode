class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        int i = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(mid+1<nums.size() && nums[mid] > nums[mid+1]){
                i = mid;
                break;
            }else if(nums[mid] >= nums[0]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return i == -1 ? nums[0] : nums[i+1];
    }
};
