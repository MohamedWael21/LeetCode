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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int i = postorder.size()-1;
        function<TreeNode*(int, int)> sv = [&](int s, int e) -> TreeNode*{
            if(s>e) return nullptr;
            TreeNode* curr = new TreeNode();
            int pos = mp[postorder[i--]];
            curr->val = inorder[pos];
            curr->right = sv(pos+1, e);
            curr->left = sv(s, pos-1);
            return curr;
        };
        TreeNode* ans = sv(0, inorder.size()-1);
        return ans;
    }
};
