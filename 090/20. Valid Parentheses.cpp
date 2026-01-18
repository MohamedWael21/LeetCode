class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            if((c == ')' || c == ']' || c == '}') && st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            if(c == ')' || c == ']' || c == '}') st.pop();
        }
        return st.empty();
    }
};