class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int i=0, j=0;
        int cost = 0;
        while(j<t.size()){
            cost += abs(s[j]-t[j]);
            while(cost > maxCost && i<=j){
                cost -= abs(s[i]-t[i]);
                i++;
            }
            if(i>j){
                i = j = j+1;
                continue;
            }
            ans = max(ans, j-i+1);    
            j++;
        }

        return ans;
    }
};
