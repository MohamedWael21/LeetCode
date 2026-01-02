
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int>b){
            return a[0] < b[0];
        });

        vector<int>curr = intervals[0];

        auto merge = [&](vector<int>a, vector<int>b){
            vector<int> result = {a[0], max(a[1], b[1])};
            return result;
        };

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= curr[1] || intervals[i][1] <= curr[1] )
                curr = merge(curr, intervals[i]);
            else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }

        ans.push_back(curr);


        return ans;
    }
};
