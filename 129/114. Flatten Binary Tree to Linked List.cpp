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
    TreeNode* sv(TreeNode* root){
        if(!root) return root;
        TreeNode* left = sv(root->left);
        TreeNode* right = sv(root->right);
        root->right = left;
        if(!left){
            root->right = right;
            return root;
        }
        while(left->right) left = left->right;
        left->right = right;
        root->left = nullptr;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        root = sv(root);
    }
};
