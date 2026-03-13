class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        function<bool(int,int,int)> dfs = [&](int i,int j,int idx){
            if(idx == word.size()) return true;

            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni<0 || ni>=n || nj<0 || nj>=m) continue;
                if(board[ni][nj] != word[idx]) continue;

                char temp = board[ni][nj];
                board[ni][nj] = '#';

                if(dfs(ni,nj,idx+1)) return true;

                board[ni][nj] = temp;
            }
            return false;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    char temp = board[i][j];
                    board[i][j] = '#';

                    if(dfs(i,j,1)) return true;

                    board[i][j] = temp;
                }
            }
        }

        return false;
    }
};
