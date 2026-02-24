class Solution {
    int dx4[4] = {1, 0, -1, 0};
    int dy4[4] = {0, 1, 0, -1};
    int n, m;
    bool check(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        function<void(int, int)> dfs = [&](int i, int j){
            visited[i][j] = true;
            for(int k=0; k<4; k++){
                int newI = i+dx4[k];
                int newJ = j+dy4[k];
                if(check(newI, newJ) && !visited[newI][newJ] && grid[newI][newJ] == '1'){
                    dfs(newI, newJ);
                }
            }
        };
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};
