class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>mp1, mp2;
        stringstream ss1(s1), ss2(s2);
        string curr;
        while(ss1 >> curr) mp1[curr]++;
        while(ss2 >> curr) mp2[curr]++;
        vector<string>ans;
        for(auto ele : mp1){
            if(mp2[ele.first] < 1 && ele.second == 1) ans.push_back(ele.first);
        }
        for(auto ele : mp2){
            if(mp1[ele.first] < 1 && ele.second == 1) ans.push_back(ele.first);
        }
        return ans;
    }
};