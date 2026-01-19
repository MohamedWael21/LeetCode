/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)>sv = [&](int low, int high) -> TreeNode* {
            if(low>high) return nullptr;
            int mid = (low+high)/2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = sv(low, mid-1);
            node->right = sv(mid+1, high);
            return node;
        };
        return sv(0, nums.size()-1);
    }
};