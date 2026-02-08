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
    bool sv(TreeNode* root, int curr , int targetSum){
        if(!root) return false;
        if(!root->left && !root->right) return (curr+root->val) == targetSum;
        return sv(root->left, curr+root->val, targetSum) || sv(root->right, curr+root->val, targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return sv(root, 0, targetSum);
    }
};
