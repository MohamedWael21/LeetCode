class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        string curr = "";
        stack<char>st;
        for(char c : s){
            if(c == '(')st.push(c);
            if(c == ')') st.pop();
            curr += c;
            if(!curr.empty() && st.empty()){
                ans += (curr.substr(1, curr.size()-2));
                curr = "";
            }
        }
        return ans;
    }
};
