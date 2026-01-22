class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int>mp;
        for(string d : cpdomains){
            stringstream ss(d);
            int times;
            ss >> times;
            string dp;
            ss >> dp;
            while(dp.find('.') != string::npos){
                mp[dp] += times;
                dp = dp.substr(dp.find('.')+1, dp.size());
            }
            mp[dp] += times;

        }
        vector<string>ans;
        for(auto ele : mp){
            string s = "";
            s += to_string(ele.second);
            s += " ";
            s += ele.first;
            ans.push_back(s);
        }
        return ans;
    }
};
