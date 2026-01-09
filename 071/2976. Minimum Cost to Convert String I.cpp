class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dis[26][26]{};
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                dis[i][j] = INT_MAX;
            }
        }

        for(int i=0; i<original.size(); i++){
            dis[original[i]-'a'][changed[i]-'a'] = min( dis[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            if(source[i] == target[i]) continue;
            int c = dis[source[i]-'a'][target[i]-'a'];
            if(c >= INT_MAX) return -1;
            ans += c;
        }
        return ans;
    }
};
