./**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans;
        queue<TreeNode*>q, q2;
        q.push(cloned);
        q2.push(original);
        while(!q.empty()){
            TreeNode* curr = q.front();
            TreeNode* curr2 = q2.front();
            q.pop();
            q2.pop();

            if(curr2 == target){
                ans = curr;
                break;
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);

            if(curr2->left) q2.push(curr2->left);
            if(curr2->right) q2.push(curr2->right);
        }


        return ans;
    }
};
