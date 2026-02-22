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
    int ans = 0;
    int K;
    void sv(TreeNode* root, int& b){
        if(!root) return;
        sv(root->left, b);
        if(b+1 == K) ans = root->val;
        b++;
        sv(root->right, b);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        int b = 0;
        sv(root, b);
        return ans;
    }
};

