class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0;
        int ans = 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        for(int sz : s){
            if(i>=g.size())break;
            if(sz >= g[i]){
                i++;
                ans++;
            }
        }
        return ans;
    }
};
