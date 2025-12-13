class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            bool a[9]{};
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (a[board[i][j] - '1'])
                    return false;
                a[board[i][j] - '1'] = true;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            bool a[9]{};
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (a[board[j][i] - '1'])
                    return false;
                a[board[j][i] - '1'] = true;
            }
        }

        for (int k = 0; k < 9; k++)
        {
            bool a[9]{};
            int s;
            if (k < 3)
                s = 0;
            else if (k < 6)
                s = 3;
            else
                s = 6;
            for (int i = s; i < s + 3; i++)
            {
                int start = (k % 3) * 3;
                for (int j = start; j < start + 3; j++)
                {
                    if (board[i][j] == '.')
                        continue;
                    if (a[board[i][j] - '1'])
                        return false;
                    a[board[i][j] - '1'] = true;
                }
            }
        }

        return true;
    }
};