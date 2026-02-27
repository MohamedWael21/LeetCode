class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>>g;
        for(int i=0; i<equations.size(); i++){
            double val = values[i];
            string a = equations[i][0];
            string b = equations[i][1];
            if(g.find(a) == g.end()){
                g[a] = vector<pair<string, double>>();
            }
            if(g.find(b) == g.end()){
                g[b] = vector<pair<string, double>>();
            }
            g[a].push_back({b, val});
            g[b].push_back({a, 1/val});
        }
        function<bool(string, string, double&, map<string, bool>&)> sv = [&](string node, string dist, double& m, map<string, bool>&visited)
        {
                if(node == dist) return true;
                visited[node] = true;
                for(auto v : g[node]){
                    if(visited[v.first]) continue;
                    m*= v.second;
                    bool isFound = sv(v.first, dist, m, visited);
                    if(isFound)
                        return true;
                    m /= v.second;
                }
                return false;
        };
        vector<double>ans;
        for(auto q : queries){
            string a = q[0];
            string b = q[1];
            double m = 1.0;
        map<string, bool>visited;
        if(g.find(a) == g.end() || g.find(b) == g.end()){
            ans.push_back(-1.0);
            continue;
        }
            if(sv(a, b, m, visited)){
                ans.push_back(m);
            }else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};
