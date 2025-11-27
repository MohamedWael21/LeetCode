class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int s = -1;
        int len = 0;
        int i=0;
        while(true){
            bool flag = true;
            for(int j=0; j<strs.size(); j++){
                if(i>=strs[j].size()) flag = false;
            }
            if(!flag) break;
            bool flag2 = true;
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i] != strs[j-1][i]) flag2 = false;
            }
            if(!flag2){
                break;
            }
            if(s == -1){
                s = i;
                len++;
            }else{
                len++;
            }
            i++;
        }   

        if(len == 0) return "";
        return strs[0].substr(s, len);
    }
};