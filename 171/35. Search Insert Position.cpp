/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let l =-1, r=nums.length;
    while(r-l > 1){
        let mid = Math.floor(l+(r-l)/2);
        if(nums[mid] >= target) r = mid;
        else l = mid;
    }
    return r;
};
