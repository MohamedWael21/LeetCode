class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum = 0;
        vector<int>ans(code.size(), 0);
        if(k == 0) return ans;

        auto inc = [&](int i){
            return (i+1)%code.size();
        };   

        int i;
        if(k < 0) i = (k+code.size())%code.size();
        else i = inc(0);
        k = abs(k);

        for(int j=0;j<k; j++){
            sum += code[(i+j)%code.size()];
        }

        for(int j=0; j<code.size(); j++){
            ans[j] = sum;
            sum -= code[i];
            sum += code[inc(i+k-1)];
            i = inc(i);
        }



        return ans;
    }
};
