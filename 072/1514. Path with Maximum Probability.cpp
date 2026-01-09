class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<int, double>>>adj(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back({b, succProb[i]});
            adj[b].push_back({a, succProb[i]});
        }

        priority_queue<pair<double, int>>pq;
        vector<double>dis(n, 0.0);
        vector<bool>seen(n, false);
        pq.push({1.0, start_node});
        dis[start_node] = 1.0;

        while(!pq.empty()){
            auto curr = pq.top();
            int i = curr.second;
            seen[i] = true;
            pq.pop();
            for(auto [j, w] : adj[i] ){
               if(seen[j]) continue;
               if(dis[j] < dis[i] * w){
                    dis[j] = dis[i]*w;
                    pq.push({dis[j], j});
               }
            }
        }

        return dis[end_node];
    }
};
