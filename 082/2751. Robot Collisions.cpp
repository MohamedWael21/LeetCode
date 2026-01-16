class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int, int>mp;
        vector<vector<int>>robots;
        for(int i=0; i<positions.size(); i++){
            robots.push_back({positions[i], healths[i], directions[i]});
            mp[positions[i]] = i;
        }
        sort(robots.begin(), robots.end());
        stack<int>st;
        for(int i=robots.size()-1; i>=0; i--){
            if(robots[i][2] == 'L'){
                st.push(i);
                continue;
            }
            while(!st.empty() && robots[st.top()][2] == 'L' && robots[st.top()][1] < robots[i][1]){
                robots[i][1]--;
                st.pop();
            }

            if(!st.empty() && robots[st.top()][2] == 'L'  && robots[i][1] == robots[st.top()][1]){
                st.pop();
                continue;
            }
            if(st.empty() || robots[st.top()][2] == 'R')
                st.push(i);
            
            if(!st.empty() && robots[st.top()][2] == 'L')
                robots[st.top()][1]--;

        }


        vector<int>temp(positions.size(), 0);
        while(!st.empty()){
            int pos = robots[st.top()][0];
            int go = mp[pos];
            temp[go] = robots[st.top()][1];
            st.pop();
        }
        vector<int>ans;
        for(int i=0; i<temp.size(); i++){
            if(temp[i] != 0) 
                ans.push_back(temp[i]);
        }
        return ans;
    }
};