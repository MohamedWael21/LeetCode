class Solution {
public:
    int maxVowels(string s, int k) {
        int curr = 0;
        auto check = [&](char c){
            if(c == 'a' || c == 'e' || c == 'i' || c=='o' || c== 'u') return true;
            return false;
        };
        for(int i=0;i<k; i++){
            if(check(s[i]))curr++;
        }

        int ans = curr;

        for(int i=k; i<s.size(); i++){
            if(check(s[i-k])) curr--;
            if(check(s[i]))curr++;
            ans = max(ans, curr);
        }

        return ans;
    }
};
