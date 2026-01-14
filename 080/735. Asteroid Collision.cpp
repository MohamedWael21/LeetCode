class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] > 0){
                st.push(i);
                continue;
            }
            while(!st.empty() && asteroids[st.top()] < abs(asteroids[i])){
                asteroids[st.top()] = -1e5;
                st.pop();
            }

            if(!st.empty() && asteroids[st.top()] == abs(asteroids[i])){
                asteroids[st.top()] = -1e5;
                asteroids[i] = -1e5;
                st.pop();
            }
            if(!st.empty()) asteroids[i] = -1e5;

        }

        vector<int>ans;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] != -1e5) ans.push_back(asteroids[i]);
        }
        return ans;
    }
};