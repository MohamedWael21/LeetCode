class Solution {
public:
    struct Pair{
        int s; 
        int i;
        int j;
    };
    struct cmp {
    bool operator()(const Pair& a, const Pair& b) {
        return a.s > b.s; 
    }
};
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
     priority_queue<Pair, vector<Pair>, cmp>p;
     vector<vector<int>>ans;
     set<pair<int, int>>visited;
     p.push({nums1[0]+nums2[0], 0, 0});
     while(!p.empty() && ans.size() < k){
        Pair curr = p.top();
        p.pop();
        ans.push_back({nums1[curr.i], nums2[curr.j]});
        if(curr.i+1 < nums1.size() && !visited.count({curr.i+1, curr.j})){
            visited.insert({curr.i+1, curr.j});
            p.push({nums1[curr.i+1]+nums2[curr.j], curr.i+1, curr.j});
        }
        if(curr.j+1 < nums2.size() && !visited.count({curr.i, curr.j+1})){
            visited.insert({curr.i, curr.j+1});

            p.push({nums1[curr.i]+nums2[curr.j+1], curr.i, curr.j+1});
        }
     }
     return ans;
    }
};
