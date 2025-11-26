class Solution {
public:
    string intToRoman(int num) {
        string currNum = to_string(num);

        int pw = pow(10, currNum.size()-1);
        map<int, string>mp;
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";

        vector<int>roman = {1, 5, 10, 50 , 100, 500 ,1000};

        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[400] = "CD";
        mp[900] = "CM";
        string res = "";
        for(int i=0; i<currNum.size(); i++){
            int n = (currNum[i]-'0')*pw;
            if(mp.find(n) != mp.end()) res += mp[n];
            else{
                while(n){
                    auto it = upper_bound(roman.begin(), roman.end(), n);
                    --it;
                    res += mp[*it];
                    n -= (*it);

                }

            }
            pw /=10;
        }
        return res;
    }
};