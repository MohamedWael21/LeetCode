class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int>q;
        for(int num : nums){
            q.push(num);
        }
        while(k--){
            int num = q.top();
            ans +=num;
            q.pop();
            int newNum = (num+2)/3;
            q.push(newNum);
        }
        return ans;
    }
};
