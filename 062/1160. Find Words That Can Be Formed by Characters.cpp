class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int hav[26]{};
        for(char c : chars) hav[c-'a']++;
        int ans = 0;
        for(string word : words){
            int need[26]{};
            for(char c : word) need[c-'a']++;
            bool flag = true;
            for(char c='a'; c<='z'; c++){
                if(need[c-'a'] > hav[c-'a']){
                    flag = false;
                    break;
                }
            }
            if(flag) ans += word.size();
        }

        return ans;
    }
};
