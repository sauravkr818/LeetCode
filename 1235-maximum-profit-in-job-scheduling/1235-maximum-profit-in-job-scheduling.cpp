class Solution {
public:
    // important question on binary search
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        map<int,int>dp = {{0,0}};
        vector<vector<int>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({endTime[i],startTime[i],profit[i]});
        }
        // sort in terms of endTime
        sort(temp.begin(),temp.end());
        int tmp = 0;
        for(auto&job: temp){
            int stTime = job[1];
            int enTime = job[0];
            int pft = job[2];
            // important step to find the just smaller index than stTime so use prev(dp.upper_bound(stTime))->second to get the profit and first to get the index.
            int cur = prev(dp.upper_bound(stTime))->second + pft;
            tmp = max(tmp,cur);
            dp[enTime] = tmp;
        }
        
        // find the max out of all the profits stored in the map
        int ans = 0;
        for(auto t: dp){
            ans = max(ans,t.second);
        }
        return ans;
    }
};