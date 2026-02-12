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
    int lh(TreeNode* root){
        if(!root) return 0;
        return 1 + lh(root->left);
    }
    int rh(TreeNode* root){
        if(!root) return 0;
        return 1 + rh(root->right);
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = lh(root);
        int r = rh(root);
        if(l == r) return (1<<l)-1;
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
