/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans;
    bool sv(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;    
        bool left = sv(root->left, p, q);
        bool right = sv(root->right, p, q);
        if((root == p || root == q)){
            if(left || right){
                ans = root;
            }
            return true;
        } else if(left && right && !ans){
            ans = root;
            return true;
        }
        return left || right;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        sv(root, p, q);
        return ans;
    }
};
