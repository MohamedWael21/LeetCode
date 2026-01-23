class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>q(gifts.begin(), gifts.end());
        while(k--){
            int mx = q.top();
            q.pop();
            q.push((int)sqrt(mx));
        }
        long long ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;

    }
};
