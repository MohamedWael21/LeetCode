class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       int ans = 0;
       int cum = 0;
       for(int i=0; i<gain.size(); i++){
        cum += gain[i];
        ans = max(ans, cum);
       }

       return ans;
    
    }  
};
