class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       int n = arr.size();
       vector<int>prefix(n, 0);
       prefix[0] = arr[0];
       for(int i=1; i<n; i++){
        prefix[i] = arr[i] ^ prefix[i-1];
       }

       vector<int>ans;

        for(int i=0; i<queries.size(); i++){
            int start = queries[i][0];
            int end = queries[i][1];

            int val = prefix[end];

            if(start-1 >= 0) val ^= prefix[start-1];

            ans.push_back(val);

        }


       return ans;
    }
};
