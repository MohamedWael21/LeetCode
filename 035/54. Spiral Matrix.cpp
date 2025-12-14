class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> a(n, vector<bool>(m, false));
        int i = 0, j = 0;
        vector<int> ans;

        int diri = 0, dirj = 1;
        int cnt = 0;
        int state = 0;
        while (true)
        {
            if (cnt == n * m)
                break;
            ans.push_back(matrix[i][j]);
            a[i][j] = true;

            if (i + diri >= n || j + dirj >= m || i + diri < 0 || j + dirj < 0 || a[i + diri][j + dirj])
            {
                if (state == 0)
                { // right
                    diri = 1;
                    dirj = 0;
                    state = 1;
                }
                else if (state == 1)
                { // /down
                    diri = 0;
                    dirj = -1;
                    state = 2;
                }
                else if (state == 2)
                { // left
                    diri = -1;
                    dirj = 0;
                    state = 3;
                }
                else if (state = 3)
                { // up
                    diri = 0;
                    dirj = 1;
                    state = 0;
                }
            }
            i += diri;
            j += dirj;
            cnt++;
        }

        return ans;
    }
};