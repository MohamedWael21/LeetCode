class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        for(auto ele : prerequisites){
            indeg[ele[0]]++;
            adj[ele[1]].push_back(ele[0]);
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0; i<numCourses; i++){
            if(indeg[i] == 0) q.push(i); 
        }
        
        while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(int v : adj[u]){
                indeg[v]--;
                if(indeg[v] == 0)q.push(v);
            }
        }

       return ans.size() == numCourses ? ans : vector<int>();
        
    }
};
