class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     queue<int>q;
     int time = 0;
     for(int i=0; i<tickets.size(); i++) q.push(i);
     while(!q.empty()){
        time++;
        int curr = q.front();
        q.pop();
        tickets[curr]--;
        if(curr == k && tickets[curr] == 0)return time;
        if(tickets[curr] != 0) q.push(curr);
     }   
     return 0;
    }
};
