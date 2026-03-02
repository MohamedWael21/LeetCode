class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>>nums(n, vector<int>(n));
        int cnt = 1;
        int turn = true;
        map<int, pair<int, int>>mp;
        for(int r=n-1; r>=0; r--){
            if(turn)
                for(int c=0; c<=n-1; c++){
                    nums[r][c] = cnt++;
                    mp[nums[r][c]] = {r, c};
                }
            else
                for(int c=n-1; c>=0; c--){
                    nums[r][c] = cnt++;
                    mp[nums[r][c]] = {r, c};
                }
            turn = !turn;
        }

        queue<pair<int, int>>q;
        q.push({1, 0});
        vector<int>visited(n*n+1, false);
        
        while(!q.empty()){
            auto [curr, moves] = q.front();
            q.pop();
            if(curr == n * n) return moves;

            for(int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                int next = curr + dice;
                auto [r, c] = mp[next];
                if(board[r][c] != -1) {
                    next = board[r][c];
                }

                if(!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};
