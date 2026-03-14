class Solution {
public:
    int totalNQueens(int n) {
        vector<bool>d1(2*n, false);
        vector<bool>d2(2*n-1, false);
        vector<bool>col(n, false);
        function<int(int)>sv = [&](int r){
            if( r == n) return 1;
            int ans = 0;
            for(int c=0; c<n; c++){
                int d1Ind = r-c+n;
                int d2Ind = r+c;
                if(!col[c] && !d1[d1Ind] && !d2[d2Ind]){
                    col[c] = true;
                    d1[d1Ind] = true;
                    d2[d2Ind] = true;
                    ans += sv(r+1);
                    col[c] = false;
                    d1[d1Ind] = false;
                    d2[d2Ind] = false;
                }
            }
            return ans;
        };
        return sv(0);
    }
};
