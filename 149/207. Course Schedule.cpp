class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto ele : prerequisites){
            indeg[ele[0]]++;
            adj[ele[1]].push_back(ele[0]);
        }
        while(numCourses--){
            int u = -1;
            for(int i=0; i<indeg.size(); i++){
                if(indeg[i] == 0){
                    u = i;
                    indeg[i] = -1;
                    break;
                }
            }
            if(u == -1) return false;
            for(int v : adj[u]){
                indeg[v]--;
            }
        }
        return true;
    }
};
