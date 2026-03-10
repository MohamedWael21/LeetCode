class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<char>>mp;
        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};
        vector<string>ans;
        function<void(int, string&)> sv = [&](int i, string&path){
            if(i == digits.size()){
                ans.push_back(path);
                return;
            }
            for(char c : mp[digits[i]]){
                path.push_back(c);
                sv(i+1, path);
                path.pop_back();
            }
        };
        string path = "";
        sv(0, path);
        return ans;
    }
};
