class Solution {
public:
    
    int profit = 0;
    
    // memoization + recursion
    int f(int ind, int buy,int n,vector<int>&prices,vector<vector<int>>&dp){
        // base cases
        if(ind == n){
            return 0;
        }
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max( -prices[ind] + f(ind+1,0,n,prices,dp), 0 + f(ind+1,1,n,prices,dp));
        }
        else{
            profit = max( prices[ind] + f(ind+1,1,n,prices,dp), 0 + f(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,n,prices,dp);
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0; buy<=1; buy++){
                if(buy){
                    profit = max( -prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max( prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};