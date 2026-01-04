class Solution {
public:
    int arrangeCoins(int n) {
      
      long long l = 0, r = 3*1e9;
      int ans = -1;
      while(l<=r){
        long long mid = l + (r-l) /2;
        long long need = mid*(mid+1)/2;
        if(need <= n)
        {
            ans=mid; 
            l = mid+1;
        }
        else r = mid-1;
      }

      return ans;
        
    }
};
