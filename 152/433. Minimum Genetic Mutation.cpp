class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, bool>mp;
        for(string gene : bank) mp[gene] = true;
        queue<string>q;
        unordered_map<string, bool>visited;
        vector<char>genes = {'A', 'C', 'G', 'T'};
        q.push(startGene);
        int depth = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                if(curr == endGene) return depth;
                for(int i=0; i<curr.size(); i++){
                    for(char c : genes){
                        if(c == curr[i]) continue;
                        string newS = curr;
                        newS[i] = c;
                        if(!visited[newS] && mp[newS]){
                            visited[newS] = true;
                            q.push(newS);
                        }
                    }
                }
            }

            depth++;
        }

        return -1;
    }
};
