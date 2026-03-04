class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool>mp;
        for(string word : wordList){
            mp[word] = true;
        }
        unordered_map<string, vector<string>>adj;
        wordList.push_back(beginWord);
        for(string word : wordList){
            vector<string>n;
            for(int i=0; i<word.size(); i++){
                for(char c='a'; c<='z'; c++){
                    string tmp = word;
                    if(c == tmp[i]) continue;
                    tmp[i] = c;
                    if(mp[tmp]){
                        n.push_back(tmp);
                    }
                }
            }
            adj[word] = n;
        }
        unordered_map<string, bool>visited;
        queue<string>q;
        q.push(beginWord);
        int depth = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                if(curr == endWord) return depth;
                visited[curr] = true;
                for(auto v : adj[curr]){
                    if(!visited[v]){
                        q.push(v);
                    }
                }
            }

            depth++;
        }
        return 0;
    }
};
