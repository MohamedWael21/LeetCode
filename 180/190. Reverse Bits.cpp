class Solution {
public:
    int reverseBits(int n) {
        int ans = n;
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                ans |= (1<<(32-i-1));
            }else{
                ans = ans & ~(1<<32-i-1);
            }
        }
        return ans;
    }
    
};