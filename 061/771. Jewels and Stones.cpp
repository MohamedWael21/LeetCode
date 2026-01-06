class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool freq[52]{};
        for(int i=0; i<jewels.size(); i++){
            char c = jewels[i];
            if(islower(c)) freq[c-'a'] =  true;
            else freq[c-'A'+26] = true;
        }   
        int ans = 0;
        for(int i=0; i<stones.size(); i++){
            char c = stones[i];
            if(islower(c)) ans += freq[c-'a'];
            else ans += freq[c-'A'+26];
        }   

        return ans;
    }
};
