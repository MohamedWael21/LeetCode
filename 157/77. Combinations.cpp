class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<bool>used(n+1, false);
        function<void(int, vector<int>&)>sv = [&](int i, vector<int>&curr){
            if(i == k){
                ans.push_back(curr);
                return;
            }
            int start = curr.size() > 0 ? curr.back()+1 : 1;
            for(int j=start; j<=n; j++){
                if(!used[j]){
                    used[j] = true;
                    curr.push_back(j);
                    sv(i+1, curr);
                    used[j] = false;
                    curr.pop_back();
                }
            }
        };
        vector<int>tmp;
        sv(0, tmp);
        return ans;
    }
};
