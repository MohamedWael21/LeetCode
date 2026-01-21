class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, bool>mp;
        for(int candy : candyType)
            mp[candy] = true;
        int cnt = 0;
        int n = candyType.size()/2;
        for(auto ele : mp){
            if(cnt == n) break;
            cnt++;
        } 
        return cnt;  
    }
};
