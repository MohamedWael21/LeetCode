class Solution {
public:
    int hIndex(vector<int>& citations) {
       int l=0, r = 1001;
       while(r-l > 1){
            int mid = l+(r-l)/2;
            int cnt = 0;
            for(int j = 0; j<citations.size(); j++){
                if(citations[j] >= mid) cnt++;
            }
            if(cnt>= mid) l = mid;
            else r = mid;
       }
       return l;
    }
};