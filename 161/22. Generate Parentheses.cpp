class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        vector<string>ans;
        function<void(int, string)> sv = [&](int i, string curr){
            if(i == 2*n){
                if(open == 0)
                    ans.push_back(curr);
                return;
            }
            if(open<n){
                open++;
                sv(i+1, curr+"(");
                open--;
            }
            if(open){
                open--;
                sv(i+1, curr+")");
                open++;
            }
        };
        sv(0, "");
        return ans;
    }
};
