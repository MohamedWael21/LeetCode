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
    int getMax(TreeNode* root){
        if(!root) return 1e6;
        if(!root->right) return root->val;
        return getMax(root->right);
    }
    int getMin(TreeNode* root){
        if(!root) return 1e6;
        if(!root->left) return root->val;
        return getMin(root->left);
    }
    int ans = 1e6;
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 1e6;
        int mx = getMax(root->left);
        int mi = getMin(root->right);
        return min({abs(root->val-mx), abs(root->val-mi), getMinimumDifference(root->left), getMinimumDifference(root->right)});
    }
};
