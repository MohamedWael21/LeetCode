class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26]{};
        for(char c : s) freq[c-'a']++;
        int co = 0;
        int v = 0;
        auto check = [&](char c){
            return c=='a' || c =='e' || c=='i' || c=='o' || c == 'u';
        };
        for(char c : s){
            if(check(c)) v = max(v, freq[c-'a']);
            else co = max(co, freq[c-'a']);
        }

        return co+v;

    }
};
