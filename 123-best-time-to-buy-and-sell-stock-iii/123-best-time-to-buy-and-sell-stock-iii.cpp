class Solution {
public:
    int f(int ind, int buy, int transactionsAllowed,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
        // base cases
        if(ind == n || transactionsAllowed == 0) return dp[ind][buy][transactionsAllowed] = 0;
        if(dp[ind][buy][transactionsAllowed] != -1) return dp[ind][buy][transactionsAllowed];
        
        int profit = 0;
        
        if(buy){
            profit = max( -prices[ind] + f(ind+1,0,transactionsAllowed,prices,n,dp),
                        0 + f(ind+1, 1, transactionsAllowed, prices, n,dp));
        }
        else{
            profit = max( prices[ind] + f(ind+1,1,transactionsAllowed-1,prices,n,dp),
                        0 + f(ind+1,0,transactionsAllowed, prices,n,dp));
        }
        return dp[ind][buy][transactionsAllowed] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
    }
};