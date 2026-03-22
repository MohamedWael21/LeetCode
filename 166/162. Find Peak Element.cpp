class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        int l =0; 
        int r = n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(((mid-1)<0 || a[mid] >a[mid-1]) && (mid+1>=n || a[mid] > a[mid+1])){
                return mid;
            }else if(mid+1>=n || a[mid] < a[mid+1]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return 0;
    }
};
