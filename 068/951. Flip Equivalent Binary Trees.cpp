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
    bool sv(TreeNode* root1, TreeNode* root2){
        if(root1 == root2) return true;
        if(!root1 || !root2) return false;
        if(!root1->left && !root1->right && !root2->left && !root2->right)
            return root1->val == root2->val;
            

        bool left = sv(root1->left, root2->left);
        bool right;
        if(!left) {
            left = sv(root1->left, root2->right);
            right = sv(root1->right, root2->left);  
        }else
            right = sv(root1->right, root2->right);
            

        bool ans = left & right & (root1->val == root2->val);

        return ans;
        
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == root2) return true;
        return sv(root1, root2);
    }
};
