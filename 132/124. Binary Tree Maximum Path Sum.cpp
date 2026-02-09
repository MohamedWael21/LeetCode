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
    int mx;
    int sv(TreeNode* root){
        if(!root) return 0;
       int pl = sv(root->left);
        int pr = sv(root->right);
        mx = max(mx, pl+pr+root->val);
        mx = max(mx, root->val);
        mx = max(mx, pl+root->val);
        mx = max(mx, pr+root->val);
        return max(max(pl, pr) + root->val, root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        mx = -1e6;
        sv(root);
        return mx;
    }
};
