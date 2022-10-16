class Solution {
public:
    int f(int i, vector<int>&job, int d, vector<vector<int>>&dp){
        // base case
        if(i == job.size() && d == 0) return 0;
        
        if(job.size() - i<d) return 1e5;
        
        if(d<0) return 1e5; 
        
        if(dp[i][d] != -1) return dp[i][d];
        int maxi = 0;
        int res = INT_MAX;
        for(int idx = i;idx<job.size();idx++){
            maxi = max(maxi,job[idx]);
            res = min(res, maxi+ f(idx+1,job,d-1,dp));
        }
        return dp[i][d] = res;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(d>n) return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return f(0,job,d,dp);
    }
};