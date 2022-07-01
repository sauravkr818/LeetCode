class Solution {
public:
    
    // recursion + memoization
    
    int f(int ind, int buy, int transactionsAllowed,vector<int>& prices,int n,vector<vector<vector<int>>>&dp){
        // base cases
        if(ind == n || transactionsAllowed == 0) return dp[ind][buy][transactionsAllowed] = 0;
        
        if(dp[ind][buy][transactionsAllowed] != -1) return dp[ind][buy][transactionsAllowed];
        
        int profit = 0;
        
        if(buy){
            // max( either buy on the ith day and move to (i+1)th day to sell or not buy on the ith day and move to (i+1)th day).
            profit = max( -prices[ind] + f(ind+1,0,transactionsAllowed,prices,n,dp),
                        0 + f(ind+1, 1, transactionsAllowed, prices, n,dp));
        }
        else{
            // max( either sell on the ith day and move to (i+1)th day to buy or not sell on the ith day and move to (i+1)th day).
            profit = max( prices[ind] + f(ind+1,1,transactionsAllowed-1,prices,n,dp),
                        0 + f(ind+1,0,transactionsAllowed, prices,n,dp));
        }
        return dp[ind][buy][transactionsAllowed] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        
        //return f(0,1,2,prices,n,dp);
        
        // tabulation
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        // bases cases return 0 but since we have initiallized our dp array to 0 hence we need not write base cases
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    // copy paste the recurrence
                    int profit = 0;
                    if(buy){
                        profit = max( -prices[ind] + dp[ind+1][0][cap],
                                    0 + dp[ind+1][1][cap] );
                    }
                    else{
                        // max( either sell on the ith day and move to (i+1)th day to buy or not sell on the ith day and move to (i+1)th day).
                        profit = max( prices[ind] + dp[ind+1][1][cap-1] ,
                                    0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};