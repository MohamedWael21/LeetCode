class Solution {
    int longest(vector<vector<int>>&adj, int i, int p){
        int path = 0;
        for(int j : adj[i]){
            if(j==p) continue;
            path = max(path, longest(adj, j, i)+1);
        }

        return path;
    }
    int diam(vector<vector<int>>&adj, int i, int p, int&d){
        int mx = 0, mx2 = 0;
        for(int j : adj[i]){
            if(j == p) continue;
            int ret = 1 + diam(adj, j, i, d);
            if(ret > mx){
                mx2 = mx;
                mx = ret;
            }else if(ret > mx2)mx2 = ret;
        }
       d = max(d, mx+mx2);
        return mx;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);
        for(auto edg : edges1){
            adj1[edg[0]].push_back(edg[1]);
            adj1[edg[1]].push_back(edg[0]);
        }

        for(auto edg : edges2){
            adj2[edg[0]].push_back(edg[1]);
            adj2[edg[1]].push_back(edg[0]);
        }
        int d1 = 0, d2=0;
        diam(adj1, 0, -1, d1);
        diam(adj2, 0, -1, d2);

        int l = ((d1+1)/2) + ((d2+1)/2) + 1;

        return max({d1, d2, l});



    }
};
