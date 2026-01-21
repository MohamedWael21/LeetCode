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
    TreeNode* sv(TreeNode* root, int val){
        if(!root) return nullptr;
        if(root->val == val) return root;
        TreeNode* ans;
        ans = sv(root->left, val);
        if(!ans)
            ans = sv(root->right, val);
        
        return ans;

    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return sv(root, val);
    }
};