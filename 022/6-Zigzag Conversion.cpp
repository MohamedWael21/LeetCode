class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>a(numRows, "");
        int dir = 1;
        int row = 1;
        int i = 0;
        while(i<s.size()){
            a[row-1] += s[i];
            
            if(row == numRows) dir = -1;
            else if(row == 1) dir = 1;
            row+=dir; 
            i++;
        }
        string ans = "";
        for(auto e : a){
            ans += e;
        }
        return ans;
    }
};