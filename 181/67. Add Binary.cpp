class Solution {
public:
    string addBinary(string a, string b) {
       string ans = "";
       bool carry = false;
       int i = a.size()-1;
       int j = b.size()-1;
       while(i>=0 && j>=0){
            int curr = (a[i]-'0') + (b[j]-'0') + carry;
            if(curr == 0 || curr == 2) ans += "0";
            if(curr == 1 || curr == 3) ans += "1";
            carry = false;
            if(curr == 2 || curr == 3) carry = true;
            i--;
            j--;
       }

       while(i>=0){
        int curr = (a[i]-'0') + carry;
        if(curr == 0 || curr == 2) ans += "0";
        if(curr == 1) ans += "1";
        carry = false;
        if(curr == 2) carry = true;
        i--;
       }
        while(j>=0){
        int curr = (b[j]-'0') + carry;
        if(curr == 0 || curr == 2) ans += "0";
        if(curr == 1) ans += "1";
        carry = false;
        if(curr == 2) carry = true;
        j--;
       }
       if(carry) ans += "1";
       reverse(ans.begin(), ans.end());
       return ans;   

    }
};
