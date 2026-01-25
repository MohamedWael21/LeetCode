class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto check = [&](vector<int>interval1, vector<int>interval2){
            if(interval1[0] >= interval2[0] && interval1[0] <= interval2[1]) return true;
        if(interval2[0] >= interval1[0] && interval2[0] <= interval1[1]) return true;
        return false;
        };
        vector<vector<int>>ans;
        vector<int>prev = newInterval;
        int i = 0;
        if(intervals.size() == 0) return {newInterval};
        if(prev[1] < intervals[0][0]){ans.push_back(prev); prev[0] = -1;};
        while(i<intervals.size()){
            if(prev[0] != -1 && prev[1] < intervals[i][0]){
                ans.push_back(prev);
                prev[0] = -1;
            }
            if(prev[0] == -1 || intervals[i][1] < prev[0]){
                ans.push_back(intervals[i]);
                i++;
                continue;
            }
            while(i<intervals.size() && check(prev, intervals[i])){
                prev[0] = min(intervals[i][0], prev[0]);
                prev[1] = max(intervals[i][1], prev[1]);
                i++;
            }
            ans.push_back(prev);
            prev[0] = -1;
            prev[1] = -1;
        }
        if(prev[0] != -1){
            ans.push_back(prev);
        }
        return ans;
    }
};
