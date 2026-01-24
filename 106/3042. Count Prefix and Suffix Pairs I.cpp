class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                string str1 = words[i];
                string str2 = words[j];
                if(str1.size() > str2.size()) continue;
                string pref = str2.substr(0, str1.size());
                string suff = str2.substr(str2.size()-str1.size());
                if(pref == str1 && suff == str1) ans++;
            }
        }
        return ans;
    }
};
