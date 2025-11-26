class Solution {
public:
    int lengthOfLastWord(string st) {
        int e = -1;
        int s = -1;
        for(int i=st.size()-1; i>=0; i--){
            if(st[i] == ' ' && e != -1) break;
            if(st[i] != ' ' && e == -1){
                e = i;
            } 
            if(st[i] != ' ') s = i;
        }   
        if(s == -1) return 0;
        return e-s+1;
    }
};