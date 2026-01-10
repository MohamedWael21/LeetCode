class Solution {
    int sv(int i, int j, string word1, string word2,  vector<vector<int>>&dp){
        if(i >= word1.size()) return word2.size()-j;
        if(j >= word2.size()) return word1.size()-i;
        
        int&ret = dp[i][j];

        if(ret != -1) return dp[i][j];
        ret = INT_MAX;

        if(word1[i] == word2[j])
            ret = sv(i+1, j+1, word1, word2, dp);
        else
            ret = min({sv(i+1, j+1, word1, word2, dp), sv(i+1, j, word1, word2, dp), sv(i, j+1, word1, word2, dp)}) + 1;

        return ret;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        return sv(0, 0, word1 , word2, dp);
    }
};
