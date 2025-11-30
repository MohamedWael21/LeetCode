class Solution {
public:
    string reverseWords(string s) {
        bool flag = false;
        reverse(s.begin(), s.end());

        auto it = s.begin();

        while (it != s.end()) {
            while (it != s.end() && *it == ' ')
                it++;

            auto start = it;

            while (it != s.end() && *it != ' ')
                it++;

            reverse(start, it);
        }

        int ins = 0;
        int curr = 0;
        while(curr < s.size()){
            while(curr <s.size() && s[curr]==' ') curr++;
            while(curr<s.size() && s[curr] != ' '){
                s[ins++] = s[curr++];
            }
            s[ins] = ' ';
            ins++;
        }
        while(s[ins-1] == ' ')ins--;
        return s.substr(0, ins);
    }
};