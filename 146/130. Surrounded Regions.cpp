class Solution {
    int dx4[4] = {1, 0, -1, 0};
    int dy4[4] = {0, 1, 0, -1};
    int n, m;
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        function<void(int, int)> dfs = [&](int i, int j){
            if(i>=n || i<0 || j>=m || j<0) return;
            if(visited[i][j] || board[i][j] == 'X') return;
            visited[i][j] = true;
            board[i][j] = 'D'; 
            for(int k=0; k<4; k++){
                dfs(dx4[k]+i, dy4[k]+j);
            }
        };
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j);
            if(board[n-1][j] == 'O' && !visited[n-1][j])
                dfs(n-1, j);
        }   
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0);
            if(board[i][m-1] == 'O' && !visited[i][m-1])
                dfs(i, m-1);
        }  
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'D') board[i][j] = 'O';
            }
        }

    }
};
