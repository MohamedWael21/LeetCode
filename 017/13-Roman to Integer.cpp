class Solution {
public:
    bool check(int i, string s){
    if(s[i] == 'I' && i+1 <s.size() && (s[i+1] == 'V'|| s[i+1] == 'X')) return true;
    if(s[i] == 'X' && i+1 <s.size() && (s[i+1] == 'L'|| s[i+1] == 'C')) return true;
        if(s[i] == 'C' && i+1 <s.size() && (s[i+1] == 'D'|| s[i+1] == 'M')) return true;

        return false;

    }
    int romanToInt(string s) {
        map<char, int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int i = 0;
        int ans = 0;
        while(i < s.size()){
            if(check(i, s)){
                ans += mp[s[i+1]] - mp[s[i]];
                i++;
            }else{
                ans += mp[s[i]];
            }

            i++;
        }
        return ans;
    }
};