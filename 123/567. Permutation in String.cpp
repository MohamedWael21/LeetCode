class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        int a[26]{};
        int a2[26]{};
        for(int i=0; i<s1.size(); i++){
            a[s1[i]-'a']++;
            a2[s2[i]-'a']++;

        }
        bool isSame = true;
        for(char c='a'; c<='z'; c++){
            isSame &= a[c-'a'] == a2[c-'a'];
        }
        if(isSame) return true;
        for(int i=s1.size(); i<s2.size(); i++){
            a2[s2[i]-'a']++;
            a2[s2[i-s1.size()]-'a']--;        
            bool isSame = true;
            for(char c='a'; c<='z'; c++){
                isSame &= a[c-'a'] == a2[c-'a'];
            }
            if(isSame) return true;
        }
        return false;
    }
};
