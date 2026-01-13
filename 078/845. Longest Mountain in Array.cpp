class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int n = arr.size();
        vector<int>mi(n);
        vector<int>mi2(n);
        mi[0] = 1;
        for(int i=1; i<n; i++)
            if(arr[i] > arr[i-1])
                mi[i] = mi[i-1] + 1;
            else
                mi[i] = 1;

        mi2[n-1] = 1;
        for(int i=n-2; i>=0; i--)
            if(arr[i] > arr[i+1])
                mi2[i] =  mi2[i+1] + 1;
            else 
                mi2[i] = 1;
        
        int ans = 0;
        for(int i=1; i<n-1; i++){
            int prev = mi[i-1];
            int next = mi2[i+1];
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1])
                ans = max(ans, next+prev+1);
        }
        return ans;
    }
};
