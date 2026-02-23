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
    TreeNode* UN_L;
    TreeNode* UN_U;

    bool sv(TreeNode* root, TreeNode*l, TreeNode* u){
        if(!root) return true;
        if(l != UN_L && root->val <= l->val) return false;
        if(u != UN_U && root->val >= u->val) return false;
        return sv(root->left, l, root) && sv(root->right, root, u);
    }

public:
    bool isValidBST(TreeNode* root) {
        UN_L = new TreeNode();
        UN_U = new TreeNode();
        return sv(root, UN_L, UN_U);
    }   
};
