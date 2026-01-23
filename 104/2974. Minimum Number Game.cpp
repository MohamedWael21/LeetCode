class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>q(nums.begin(), nums.end());
        vector<int>ans;
        while(!q.empty()){
            int alice = q.top();
            q.pop();
            int bob = q.top();
            q.pop();
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};
