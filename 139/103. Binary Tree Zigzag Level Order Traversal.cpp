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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(!root) return ans;
        int turn = 0;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int sz = q.size();
            stack<TreeNode*>st;
            while(sz--){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(turn == 0){
                 if(curr->left)
                    st.push(curr->left);
                 if(curr->right)
                    st.push(curr->right);
                }else{
                    if(curr->right)
                        st.push(curr->right);
                    if(curr->left)
                        st.push(curr->left);
                }
            }
            turn = (turn+1)%2;
            ans.push_back(temp);
            while(!st.empty()){
                q.push(st.top());
                st.pop();
                
            }
        }
        return ans;
    }
};
