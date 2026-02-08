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
    int sv(TreeNode* root, int curr){
        if(!root) return 0;
        curr = curr*10 + root->val;
        if(!root->left && !root->right) return curr;
        int left = sv(root->left, curr);
        int right = sv(root->right, curr);
        return left+right;
    }
public:
    int sumNumbers(TreeNode* root) {
        return sv(root, 0);
    }
};
