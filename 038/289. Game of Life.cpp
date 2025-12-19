class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        const int dx8[] = {1, 1, 1, 0, 0, -1, -1, -1};
        const int dy8[] = {1, 0, -1, 1, -1, 1, 0, -1};
        auto check = [&](int i, int j)
        {
            return i < n && i >= 0 && j < m && j >= 0;
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int lives = 0;
                for (int k = 0; k < 8; k++)
                {
                    int newI = dx8[k] + i;
                    int newJ = dy8[k] + j;
                    if (check(newI, newJ) && (board[newI][newJ] == 1 || board[newI][newJ] == -1))
                        lives++;
                }
                if (board[i][j] == 1 && lives < 2)
                    board[i][j] = -1;
                else if (board[i][j] == 1 && lives > 3)
                    board[i][j] = -1;
                else if (board[i][j] == 0 && lives == 3)
                    board[i][j] = -2;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == -2)
                    board[i][j] = 1;
            }
        }
    }
};