class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string token : tokens){
            if(token != "+" && token != "/" && token != "-" && token != "*"){
                st.push(stoi(token));
                continue;
            }
            int y = st.top();
            st.pop();
            int x = st.top();
            st.pop();
            int res;
            if(token == "+"){
                res = x+y;
            }else if(token == "-"){
                res = x-y;
            }else if (token == "/"){
                res = x/y;
            }else{
                res = x*y;
            }
            st.push(res);
        }
        return st.top();
        
    }
};
