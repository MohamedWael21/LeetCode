class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>st;
        int i =0;
        while(i<path.size()){
            if(i<path.size() && path[i] == '/'){
                i++;
                continue;
            }
            string s = "";
           while(i<path.size() && path[i] != '/'){
                s += path[i];
                i++;
           }
            if(s == ".") continue;
            else if(s == ".." && !st.empty()) st.pop();
            else if(s != "..") st.push(s);
        }

        vector<string>a;
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        string ans = "";
        for(int i=a.size()-1; i>=0; i--){
            ans += "/";
            ans += a[i];
        }
  

        if(ans == "") return "/";

        return ans;  
    }
};
