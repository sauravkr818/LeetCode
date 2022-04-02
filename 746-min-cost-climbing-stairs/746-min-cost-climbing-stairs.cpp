class Solution {
public:
    
    int f(int n, vector<int>&cost, vector<int>&dp){
        if( n < 0) return 0;
        if(n == 0) return cost[0];
        if( n == 1) return cost[1];
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = cost[n] + min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // memoization
        vector<int>dp(n,-1);
        return min(f(n-1,cost,dp),f(n-2,cost,dp));
    }
};