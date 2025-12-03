class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;

        int i = 0;
        while(i<haystack.size()){
            bool flag = true;
            int j = 0;
            for( ;j<needle.size() && i+j<haystack.size(); j++){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag && j == needle.size()) return i;
            i++;
        }
        return -1;
    }
};